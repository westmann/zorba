/*
 * Copyright 2006-2016 zorba.io
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
#ifndef ZORBA_SIMPLE_STORE_SHARED_TYPES_H
#define ZORBA_SIMPLE_STORE_SHARED_TYPES_H

#include "store/api/shared_types.h"

namespace zorba 
{

namespace store
{
  class IndexEntryCreator;
}

  
namespace simplestore 
{

class AtomicItem;
typedef store::ItemHandle<AtomicItem> AtomicItem_t;

class XmlTree;
typedef rchandle<XmlTree> XmlTree_t;

class XmlNode;
typedef store::ItemHandle<class XmlNode> XmlNode_t;

class IndexImpl;
typedef rchandle<IndexImpl> IndexImpl_t;

typedef rchandle<store::IndexEntryCreator> IndexEntryCreator_t;

namespace json {

class JSONItem;
class JSONObject;
class SimpleJSONObject;
class JSONArray;
class SimpleJSONArray;
class JSONObjectPair;
class JSONTree;

typedef store::ItemHandle<JSONItem>         JSONItem_t;
typedef store::ItemHandle<JSONObject>       JSONObject_t;
typedef store::ItemHandle<SimpleJSONObject> SimpleJSONObject_t;
typedef store::ItemHandle<JSONArray>        JSONArray_t;
typedef store::ItemHandle<SimpleJSONArray>  SimpleJSONArray_t;
typedef store::ItemHandle<JSONObjectPair>   JSONObjectPair_t;
typedef store::ItemHandle<JSONTree>         JSONTree_t;

} /* namespace json */

class CollectionSet;

class CollectionSetIterator;
typedef rchandle<CollectionSetIterator> CollectionSetIterator_t;

}

}
#endif /* ZORBA_SIMPLE_STORE_SHARED_TYPES_H */
/* vim:set et sw=2 ts=2: */
