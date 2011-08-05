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

/* libstemmer/modules_utf8.h: List of stemming modules.
 *
 * This file is generated by mkmodules.pl from a list of module names.
 * Do not edit manually.
 *
 * Modules included by this file are: danish, dutch, english, finnish, french,
 * german, hungarian, italian, norwegian, porter, portuguese, romanian,
 * russian, spanish, swedish, turkish
 */

#include "../src_c/stem_UTF_8_danish.h"
#include "../src_c/stem_UTF_8_dutch.h"
#include "../src_c/stem_UTF_8_english.h"
#include "../src_c/stem_UTF_8_finnish.h"
#include "../src_c/stem_UTF_8_french.h"
#include "../src_c/stem_UTF_8_german.h"
#include "../src_c/stem_UTF_8_hungarian.h"
#include "../src_c/stem_UTF_8_italian.h"
#include "../src_c/stem_UTF_8_norwegian.h"
#include "../src_c/stem_UTF_8_portuguese.h"
#include "../src_c/stem_UTF_8_romanian.h"
#include "../src_c/stem_UTF_8_russian.h"
#include "../src_c/stem_UTF_8_spanish.h"
#include "../src_c/stem_UTF_8_swedish.h"
#include "../src_c/stem_UTF_8_turkish.h"

typedef enum {
  ENC_UNKNOWN=0,
  ENC_UTF_8
} stemmer_encoding_t;

struct stemmer_encoding {
  const char * name;
  stemmer_encoding_t enc;
};
static struct stemmer_encoding encodings[] = {
  {"UTF_8", ENC_UTF_8},
  {0,ENC_UNKNOWN}
};

struct stemmer_modules {
  const char * name;
  stemmer_encoding_t enc; 
  struct SN_env * (*create)(void);
  void (*close)(struct SN_env *);
  int (*stem)(struct SN_env *);
};
static struct stemmer_modules modules[] = {
  {"da", ENC_UTF_8, danish_UTF_8_create_env, danish_UTF_8_close_env, danish_UTF_8_stem},
  {"dan", ENC_UTF_8, danish_UTF_8_create_env, danish_UTF_8_close_env, danish_UTF_8_stem},
  {"danish", ENC_UTF_8, danish_UTF_8_create_env, danish_UTF_8_close_env, danish_UTF_8_stem},
  {"de", ENC_UTF_8, german_UTF_8_create_env, german_UTF_8_close_env, german_UTF_8_stem},
  {"deu", ENC_UTF_8, german_UTF_8_create_env, german_UTF_8_close_env, german_UTF_8_stem},
  {"dut", ENC_UTF_8, dutch_UTF_8_create_env, dutch_UTF_8_close_env, dutch_UTF_8_stem},
  {"dutch", ENC_UTF_8, dutch_UTF_8_create_env, dutch_UTF_8_close_env, dutch_UTF_8_stem},
  {"en", ENC_UTF_8, english_UTF_8_create_env, english_UTF_8_close_env, english_UTF_8_stem},
  {"eng", ENC_UTF_8, english_UTF_8_create_env, english_UTF_8_close_env, english_UTF_8_stem},
  {"english", ENC_UTF_8, english_UTF_8_create_env, english_UTF_8_close_env, english_UTF_8_stem},
  {"es", ENC_UTF_8, spanish_UTF_8_create_env, spanish_UTF_8_close_env, spanish_UTF_8_stem},
  {"esl", ENC_UTF_8, spanish_UTF_8_create_env, spanish_UTF_8_close_env, spanish_UTF_8_stem},
  {"fi", ENC_UTF_8, finnish_UTF_8_create_env, finnish_UTF_8_close_env, finnish_UTF_8_stem},
  {"fin", ENC_UTF_8, finnish_UTF_8_create_env, finnish_UTF_8_close_env, finnish_UTF_8_stem},
  {"finnish", ENC_UTF_8, finnish_UTF_8_create_env, finnish_UTF_8_close_env, finnish_UTF_8_stem},
  {"fr", ENC_UTF_8, french_UTF_8_create_env, french_UTF_8_close_env, french_UTF_8_stem},
  {"fra", ENC_UTF_8, french_UTF_8_create_env, french_UTF_8_close_env, french_UTF_8_stem},
  {"fre", ENC_UTF_8, french_UTF_8_create_env, french_UTF_8_close_env, french_UTF_8_stem},
  {"french", ENC_UTF_8, french_UTF_8_create_env, french_UTF_8_close_env, french_UTF_8_stem},
  {"ger", ENC_UTF_8, german_UTF_8_create_env, german_UTF_8_close_env, german_UTF_8_stem},
  {"german", ENC_UTF_8, german_UTF_8_create_env, german_UTF_8_close_env, german_UTF_8_stem},
  {"hu", ENC_UTF_8, hungarian_UTF_8_create_env, hungarian_UTF_8_close_env, hungarian_UTF_8_stem},
  {"hun", ENC_UTF_8, hungarian_UTF_8_create_env, hungarian_UTF_8_close_env, hungarian_UTF_8_stem},
  {"hungarian", ENC_UTF_8, hungarian_UTF_8_create_env, hungarian_UTF_8_close_env, hungarian_UTF_8_stem},
  {"it", ENC_UTF_8, italian_UTF_8_create_env, italian_UTF_8_close_env, italian_UTF_8_stem},
  {"ita", ENC_UTF_8, italian_UTF_8_create_env, italian_UTF_8_close_env, italian_UTF_8_stem},
  {"italian", ENC_UTF_8, italian_UTF_8_create_env, italian_UTF_8_close_env, italian_UTF_8_stem},
  {"nl", ENC_UTF_8, dutch_UTF_8_create_env, dutch_UTF_8_close_env, dutch_UTF_8_stem},
  {"nld", ENC_UTF_8, dutch_UTF_8_create_env, dutch_UTF_8_close_env, dutch_UTF_8_stem},
  {"no", ENC_UTF_8, norwegian_UTF_8_create_env, norwegian_UTF_8_close_env, norwegian_UTF_8_stem},
  {"nor", ENC_UTF_8, norwegian_UTF_8_create_env, norwegian_UTF_8_close_env, norwegian_UTF_8_stem},
  {"norwegian", ENC_UTF_8, norwegian_UTF_8_create_env, norwegian_UTF_8_close_env, norwegian_UTF_8_stem},
  {"por", ENC_UTF_8, portuguese_UTF_8_create_env, portuguese_UTF_8_close_env, portuguese_UTF_8_stem},
  {"portuguese", ENC_UTF_8, portuguese_UTF_8_create_env, portuguese_UTF_8_close_env, portuguese_UTF_8_stem},
  {"pt", ENC_UTF_8, portuguese_UTF_8_create_env, portuguese_UTF_8_close_env, portuguese_UTF_8_stem},
  {"ro", ENC_UTF_8, romanian_UTF_8_create_env, romanian_UTF_8_close_env, romanian_UTF_8_stem},
  {"romanian", ENC_UTF_8, romanian_UTF_8_create_env, romanian_UTF_8_close_env, romanian_UTF_8_stem},
  {"ron", ENC_UTF_8, romanian_UTF_8_create_env, romanian_UTF_8_close_env, romanian_UTF_8_stem},
  {"ru", ENC_UTF_8, russian_UTF_8_create_env, russian_UTF_8_close_env, russian_UTF_8_stem},
  {"rum", ENC_UTF_8, romanian_UTF_8_create_env, romanian_UTF_8_close_env, romanian_UTF_8_stem},
  {"rus", ENC_UTF_8, russian_UTF_8_create_env, russian_UTF_8_close_env, russian_UTF_8_stem},
  {"russian", ENC_UTF_8, russian_UTF_8_create_env, russian_UTF_8_close_env, russian_UTF_8_stem},
  {"spa", ENC_UTF_8, spanish_UTF_8_create_env, spanish_UTF_8_close_env, spanish_UTF_8_stem},
  {"spanish", ENC_UTF_8, spanish_UTF_8_create_env, spanish_UTF_8_close_env, spanish_UTF_8_stem},
  {"sv", ENC_UTF_8, swedish_UTF_8_create_env, swedish_UTF_8_close_env, swedish_UTF_8_stem},
  {"swe", ENC_UTF_8, swedish_UTF_8_create_env, swedish_UTF_8_close_env, swedish_UTF_8_stem},
  {"swedish", ENC_UTF_8, swedish_UTF_8_create_env, swedish_UTF_8_close_env, swedish_UTF_8_stem},
  {"tr", ENC_UTF_8, turkish_UTF_8_create_env, turkish_UTF_8_close_env, turkish_UTF_8_stem},
  {"tur", ENC_UTF_8, turkish_UTF_8_create_env, turkish_UTF_8_close_env, turkish_UTF_8_stem},
  {"turkish", ENC_UTF_8, turkish_UTF_8_create_env, turkish_UTF_8_close_env, turkish_UTF_8_stem},
  {0,ENC_UNKNOWN,0,0,0}
};
static const char * algorithm_names[] = {
  "danish", 
  "dutch", 
  "english", 
  "finnish", 
  "french", 
  "german", 
  "hungarian", 
  "italian", 
  "norwegian", 
  "portuguese", 
  "romanian", 
  "russian", 
  "spanish", 
  "swedish", 
  "turkish", 
  0
};
/* vim:set et sw=2 ts=2: */
