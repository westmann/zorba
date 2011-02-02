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
#ifndef ZORBA_STANDARD_URI_RESOLVERS_H
#define ZORBA_STANDARD_URI_RESOLVERS_H

#include "context/internal_uri_resolvers.h"

namespace zorba 
{

class URI;


class InternalResolver 
{
 public:
};


/*******************************************************************************

********************************************************************************/
class StandardDocumentURIResolver : public InternalDocumentURIResolver
{
public:
  virtual ~StandardDocumentURIResolver() {}

  virtual store::Item_t resolve(
        const store::Item_t& aURI,
        static_context* aStaticContext,
        bool validateUri,
        bool replaceDoc);
};


/*******************************************************************************

********************************************************************************/
class StandardCollectionURIResolver : public InternalCollectionURIResolver
{
public:
  virtual ~StandardCollectionURIResolver() {}

  virtual store::Collection_t resolve(
        const store::Item_t& aURI,
        static_context* aStaticContext);
};


/*******************************************************************************

********************************************************************************/
class StandardSchemaURIResolver : public InternalSchemaURIResolver
{
public:
  virtual ~StandardSchemaURIResolver() {}
      
  virtual std::string resolve(
        const store::Item_t& aURI,
        static_context* aStaticContext,
        std::vector<store::Item_t>& aAtList,
        zstring& aFileUri);

protected:
  static zstring checkSchemaPath(
        const std::vector<std::string>& aSchemaPath,
        const store::Item_t& aUri);
};


#ifndef ZORBA_NO_FULL_TEXT
/*******************************************************************************

********************************************************************************/
class StandardFullTextURIResolver : public InternalFullTextURIResolver
{
public:
  virtual ~StandardFullTextURIResolver() {}
      
  virtual zstring
  resolve(const store::Item_t& aURI,
          static_context* aStaticContext);
};
#endif /* ZORBA_NO_FULL_TEXT */

/*******************************************************************************

********************************************************************************/
class StandardModuleURIResolver : public InternalModuleURIResolver
{
public:
  virtual ~StandardModuleURIResolver() {}

  virtual void resolveTargetNamespace(
        const std::string& nsURI,
        static_context& sctx,
        std::vector<std::string>& compURIs);

  virtual std::istream* resolve(
        const std::string& uri,
        static_context& sctx,
        std::string& url);

  virtual ExternalModule* getExternalModule(
        const zstring& aFileUri,
        static_context& sctx);

protected:
  static std::istream* checkModulePath(
        const std::vector<std::string>& aModulePaths,
        const std::string& uri,
        zstring& url);

  static std::string computeLibraryName(const URI& aURI);
};


/*******************************************************************************
  This is a small helper class used when the user whants to compile a library
  module. The ONLY place it is used (and should be used) is in the 
  XQueryCompiler::createMainModule method.
********************************************************************************/
class StandardLibraryModuleURIResolver : public InternalModuleURIResolver
{
private:
  std::istream  & theStream;
  std::string     theLibraryModuleNamespace;
  std::string     theFileName;
  
public:
  StandardLibraryModuleURIResolver(
        std::istream& aXQuery,
        const std::string& lib_namespace,
        const std::string& aFileName)
    :
    theStream(aXQuery),
    theLibraryModuleNamespace(lib_namespace),
    theFileName(aFileName)
  {
  }
  
  virtual ~StandardLibraryModuleURIResolver() {}
  
  void resolveTargetNamespace(
        const std::string& nsURI,
        static_context& sctx,
        std::vector<std::string>& compURIs);

  std::istream* resolve(
        const std::string& uri,
        static_context& sctx,
        std::string& url);
};

} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
