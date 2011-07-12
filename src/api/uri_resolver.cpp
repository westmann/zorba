/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#include "stdafx.h"

#include <zorba/uri_resolvers.h>

namespace zorba {

/*************
 * Implementation of the Resource class hierarchy.
 *************/

  Resource::Resource()
  {}

  Resource::~Resource()
  {}

  StreamResource::StreamResource(std::auto_ptr<std::istream> aStream)
    : theStream(aStream)
  {}

  std::auto_ptr<std::istream>
  StreamResource::getStream()
  {
    return theStream;
  }

/*************
 * URIMapper is an abstract class, but we have to define its vtbl and
 * base destructor somewhere.
 *************/

  URIMapper::URIMapper()
  {}

  URIMapper::~URIMapper()
  {}

/*************
 * URIResolver is an abstract class, but we have to define its vtbl
 * and base destructor somewhere.
 *************/

  URLResolver::URLResolver()
  {}

  URLResolver::~URLResolver()
  {}

  /*************
   * EntityData is an abstract class, but we have to define its vtbl
   * and base destructor somewhere.
   *************/

  EntityData::~EntityData()
  {}

  /************
   * Implementation of OneToOneURIMapper.
   ************/
  OneToOneURIMapper::OneToOneURIMapper(EntityData::Kind aEntityKind,
                                       URIMapper::Kind aMapperKind)
    : theEntityKind(aEntityKind),
      theMapperKind(aMapperKind)
  {
  }

  void
  OneToOneURIMapper::mapURI(
    const String aURI,
    EntityData const* aEntityData,
    std::vector<String>& oUris)
  {
    if (aEntityData->getKind() != theEntityKind) {
      return;
    }
    MappingIter_t lIter = theMappings.find(aURI);
    if (lIter != theMappings.end()) {
      oUris.push_back(lIter->second);
    }
  }

  URIMapper::Kind
  OneToOneURIMapper::mapperKind()
  {
    return theMapperKind;
  }

  void
  OneToOneURIMapper::addMapping(
    const String& aURI, const String& aValue)
  {
    theMappings[aURI] = aValue;
  }
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
