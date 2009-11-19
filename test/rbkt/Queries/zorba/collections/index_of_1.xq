import module namespace ddl = "http://www.zorba-xquery.com/modules/ddl";
import module namespace dc = "http://www.zorba-xquery.com/modules/introspection/dctx";
import datamodule namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

declare sequential function local:test()
{
  ddl:create-collection(xs:QName("ns:test1"));
  ddl:insert-nodes-last(xs:QName("ns:test1"), <a/>);
  ddl:insert-nodes-last(xs:QName("ns:test1"), <b/>);
  ddl:insert-nodes-last(xs:QName("ns:test1"), <c/>);
  exit returning ddl:index-of(xs:QName("ns:test1"),ddl:collection(xs:QName("ns:test1"))[2]);
};

local:test()
