/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "capi/cexternal_function.h"
#include "capi/error.h"
#include "capi/capi_util.h"
#include "capi/csequence.h"
#include "zorbaerrors/error_manager.h"
#include <zorba/item_sequence.h>

using namespace zorba;

#define ZIS_TRY \
  UserItemSequence* me = UserItemSequence::get(setter); \
  try

#define ZIS_CATCH \
  catch (QueryException& qe) {                                          \
    return Error::handle_and_convert_queryexception                     \
      (me->theExternalFunction->theErrorHandler, qe);                   \
  } catch (ZorbaException &ze) {                                        \
    return Error::convert_xquery_error(ze.getErrorCode());              \
  } catch (...) {                                                       \
    return XQC_INTERNAL_ERROR;                                          \
  }                                                                     \
  return XQC_NO_ERROR


namespace zorbac {

  /**
   * A class which implements ItemSequence by getting item data from
   * the end-user and creating Items.
   */
  class UserItemSequence : public ItemSequence {
    public:
      UserItemSequence
      (StatelessExternalFunction::Arguments_t args,
        external_function_init init_fn, external_function_next next_fn,
        external_function_free free_fn, const CExternalFunction* external_fn)
        : theInitFunction(init_fn),
          theNextFunction(next_fn),
          theFreeFunction(free_fn),
          theExternalFunction(external_fn)
      {
        memset(&theItemSetter, 0, sizeof(Zorba_ItemSetter));
        theItemSetter.set_string    = UserItemSequence::set_string;
        theItemSetter.set_integer   = UserItemSequence::set_integer;
        theItemSetter.set_double    = UserItemSequence::set_double;

        if (theInitFunction) {
          theInitFunction(&theUserData,
            theExternalFunction->theFunctionUserData);
        }

        theSequencesSize = args.size();
        theSequences = new XQC_Sequence*[theSequencesSize];

        // Wrap each Argument (which is just an ItemSequence) in a
        // CSequence, and keep an array of each corresponding
        // XQC_Sequence.
        for (unsigned int i = 0; i < theSequencesSize; ++i) {
          std::auto_ptr<CSequence> lSeq(new CSequence(args[i], NULL));
          theSequences[i] = lSeq.release()->getXQC();
        }
      }

      virtual ~UserItemSequence()
      {
        if (theFreeFunction) {
          theFreeFunction(theUserData,theExternalFunction->theFunctionUserData);
        }
        delete[] theSequences;
      }

      static UserItemSequence*
      get(Zorba_ItemSetter* setter)
      {
        return (UserItemSequence*)
          (((char*)setter) - CLASS_OFFSET(UserItemSequence, theItemSetter));
      }

      virtual 
      bool next(zorba::Item& i)
      {
        XQC_Error lRes = theNextFunction(theSequences, theSequencesSize,
          &theItemSetter, theUserData,
          theExternalFunction->theFunctionUserData);
        if (lRes == XQC_END_OF_SEQUENCE)
          return false;
        if (lRes != XQC_NO_ERROR) {
          ZORBA_ERROR(XQP0019_INTERNAL_ERROR);
        }

        // theItem will have been set by the user calling back to one
        // of the Zorba_ItemSetter methods.
        i = theItem;
        assert (!i.isNull());

        return true;
      }

      // Zorba_ItemSetter methods

      static XQC_Error
      set_string(Zorba_ItemSetter* setter, const char* value)
      {
        ZIS_TRY {
          me->theItem =
            me->theExternalFunction->theFactory->createString(value);
        }
        ZIS_CATCH;
      }

      static XQC_Error
      set_integer(Zorba_ItemSetter* setter, int value)
      {
        ZIS_TRY {
          me->theItem =
            me->theExternalFunction->theFactory->createInt(value);
        }
        ZIS_CATCH;
      }

      static XQC_Error
      set_double(Zorba_ItemSetter* setter, double value)
      {
        ZIS_TRY {
          me->theItem =
            me->theExternalFunction->theFactory->createDouble(value);
        }
        ZIS_CATCH;
      }

    private:
      Zorba_ItemSetter                       theItemSetter;
      external_function_init                 theInitFunction;
      external_function_next                 theNextFunction;
      external_function_free                 theFreeFunction;
      const CExternalFunction*               theExternalFunction;
      void*                                  theUserData;
      XQC_Sequence_s**                       theSequences;
      unsigned int                           theSequencesSize;
      Item                                   theItem;
  };


  CExternalFunction::CExternalFunction
  (const char* uri, const char* localname, external_function_init init_fn,
    external_function_next next_fn, external_function_free free_fn,
    void* function_user_data, ItemFactory* factory, XQC_ErrorHandler* handler)
    : theURI(uri),
      theLocalName(localname),
      theInitFunction(init_fn),
      theNextFunction(next_fn),
      theFreeFunction(free_fn),
      theFunctionUserData(function_user_data),
      theFactory(factory),
      theErrorHandler(handler)
  {
  }

  CExternalFunction::~CExternalFunction()
  {
  }

  String
  CExternalFunction::getURI() const 
  { 
    return theURI;
  }

  String
  CExternalFunction::getLocalName() const 
  { 
    return theLocalName;
  }

  ItemSequence_t
  CExternalFunction::evaluate
  (const StatelessExternalFunction::Arguments_t& args) const
  {
    return ItemSequence_t(new UserItemSequence(args, 
        theInitFunction, theNextFunction, theFreeFunction, this));
  }

} /* namespace zorbac */
