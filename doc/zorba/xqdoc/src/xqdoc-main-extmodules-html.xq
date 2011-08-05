(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

import module namespace x2h = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/";

declare variable $modulePath          as xs:string external;
declare variable $xhtmlRequisitesPath as xs:string external;
declare variable $xqdocBuildPath      as xs:string external;
declare variable $examplePath         as xs:string external;
declare variable $zorbaVersion        as xs:string external;



x2h:copy-xhtml-requisites($modulePath,
                          $xhtmlRequisitesPath,
                          fn:trace($xqdocBuildPath,"Copy XHTML requisites in:"),
                          $examplePath);
                          

variable $indexHtmlPath as xs:string := 
fn:concat($xhtmlRequisitesPath, "/templates/main.html");

x2h:main( $modulePath,
          $xqdocBuildPath,
          $indexHtmlPath,
          $examplePath,
          $zorbaVersion,
          $xhtmlRequisitesPath);
