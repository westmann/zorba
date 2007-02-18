/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: normalize_visitor.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "normalize_visitor.h"
#include "indent.h"

#include "../parser/parsenodes.h"
#include "../util/tracer.h"

#include <iostream>

using namespace std;
namespace xqp {

static uint32_t depth = 0;


/*..........................................
 :  begin visit                            :
 :.........................................*/

bool normalize_visitor::begin_visit(parsenode const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(exprnode const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(AbbrevForwardStep const& v)
{
cout << indent[++depth] << TRACE << ": AbbrevForwardStep\n";
	return true;
}

bool normalize_visitor::begin_visit(AnyKindTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(AposAttrContentList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(AposAttrValueContent const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ArgList const& v)
{
cout << indent[++depth] << TRACE << ": ArgList" << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(AtomicType const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(AttributeTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(BaseURIDecl const& v)
{
cout << TRACE << endl;
	ctx_p->set_base_uri(v.get_base_uri());
	return false;
}

bool normalize_visitor::begin_visit(BoundarySpaceDecl const& v)
{
cout << TRACE << endl;
	ctx_p->set_boundary_space_mode(v.get_boundary_space_mode());
	return false;
}

bool normalize_visitor::begin_visit(CaseClause const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CaseClauseList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(CommentTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ConstructionDecl const& v)
{
cout << TRACE << endl;
	ctx_p->set_construction_mode(v.get_mode());
	return false;
}

bool normalize_visitor::begin_visit(CopyNamespacesDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(DefaultCollationDecl const& v)
{
cout << TRACE << endl;
	ctx_p->set_default_collation(v.get_collation());
	return false;
}

bool normalize_visitor::begin_visit(DefaultNamespaceDecl const& v)
{
cout << TRACE << endl;
	switch (v.get_mode()) {
	case ns_element_default: {
		ctx_p->set_default_elem_or_type_ns(v.get_default_namespace());
		break;
	}
	case ns_function_default: {
		ctx_p->set_default_function_ns(v.get_default_namespace());
		break;
	}
	}
	return false;
}

bool normalize_visitor::begin_visit(DirAttr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(DirAttributeList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(DirAttributeValue const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(DirElemContentList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(DocumentTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ElementTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(EmptyOrderDecl const& v)
{
cout << TRACE << endl;
	ctx_p->set_order_empty_mode(v.get_mode());
	return true;
}

bool normalize_visitor::begin_visit(ForClause const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ForLetClause const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ForLetClauseList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(ForwardAxis const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ForwardStep const& v)
{
cout << indent[++depth] << TRACE << ": ForwardStep\n";
	return true;
}

bool normalize_visitor::begin_visit(FunctionDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(GeneralComp const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Import const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(InheritMode const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ItemType const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(KindTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(LetClause const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(LibraryModule const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(MainModule  const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Module const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ModuleDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ModuleImport const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(NameTest const& v)
{
cout << indent[++depth] << TRACE << ": NameTest\n";
	return true;
}

bool normalize_visitor::begin_visit(NamespaceDecl const& v)
{
cout << TRACE << endl;
	// add namespace def to context
	return false;
}

bool normalize_visitor::begin_visit(NodeComp const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(NodeTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OccurrenceIndicator const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OptionDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OrderByClause const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OrderCollationSpec const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OrderDirSpec const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OrderEmptySpec const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OrderModifier const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OrderSpec const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OrderSpecList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(OrderingModeDecl const& v)
{
cout << TRACE << endl;
	ctx_p->set_ordering_mode(v.get_mode());
	return false;
}

bool normalize_visitor::begin_visit(PITest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Param const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ParamList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(PositionalVar const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Pragma const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(PragmaList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(PredicateList const& v)
{
cout << indent[++depth] << TRACE << ": PredicateList" << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(PreserveMode const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Prolog const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(QVarInDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(QVarInDeclList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(QuoteAttrValueContent const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(QuoteAttrContentList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(ReverseAxis const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ReverseStep const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(SIND_Decl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(SIND_DeclList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(SchemaAttributeTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(SchemaElementTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(SchemaImport const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(SchemaPrefix const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(SequenceType const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Setter const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(SignList const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(SingleType const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(TextTest const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(TypeDeclaration const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(TypeName const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(URILiteralList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(ValueComp const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(VarDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(VarGetsDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(VarGetsDeclList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(VarInDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(VarInDeclList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(VersionDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(VFO_Decl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(VFO_DeclList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(WhereClause const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Wildcard const& v)
{
cout << TRACE << endl;
	return true;
}



/* expressions */
bool normalize_visitor::begin_visit(AdditiveExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(AndExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(AxisStep const& v)
{
cout << indent[++depth] << TRACE << ": AxisStep\n";
	rchandle<axis_step_expr> aexpr_h =
		new axis_step_expr(v.get_location());
	nodestack.push(&*aexpr_h);
	return true;
}

bool normalize_visitor::begin_visit(CDataSection const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CastExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CastableExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CommonContent const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ComparisonExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CompAttrConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CompCommentConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CompDocConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CompElemConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CompPIConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(CompTextConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ComputedConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Constructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ContextItemExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(DirCommentConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(DirElemConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(DirElemContent const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(DirPIConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(DirectConstructor const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(EnclosedExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Expr const& v)
{
cout << indent[++depth] << TRACE << ": Expr\n";
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(ExprSingle const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ExtensionExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FLWORExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FilterExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FunctionCall const& v)
{
cout << indent[++depth] << TRACE << ": FunctionCall" << endl;
	rchandle<funcall_expr> fexpr_h =
		new funcall_expr(v.get_location(),v.get_fname());
	nodestack.push(&*fexpr_h);
	return true;
}

bool normalize_visitor::begin_visit(IfExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(InstanceofExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(IntersectExceptExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Literal const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(MultiplicativeExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(NumericLiteral const& v)
{
cout << indent[++depth] << TRACE << ": NumericLiteral" << endl;
	return true;
}

bool normalize_visitor::begin_visit(OrExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(OrderedExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ParenthesizedExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(PathExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(Predicate const& v)
{
cout << indent[++depth] << TRACE << ": Predicate" << endl;
	return true;
}

bool normalize_visitor::begin_visit(PrimaryExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(QuantifiedExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(QueryBody const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(RangeExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(RelativePathExpr const& v)
{
cout << indent[++depth] << TRACE << ": RelativePathExpr\n";
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(StepExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(StringLiteral const& v)
{
cout << indent[++depth] << TRACE << ": StringLiteral" << endl;
	return true;
}

bool normalize_visitor::begin_visit(TreatExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(TypeswitchExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(UnaryExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(UnionExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(UnorderedExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ValidateExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ValueExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(VarRef const& v)
{
cout << TRACE << endl;
	return true;
}



/* update-related */
bool normalize_visitor::begin_visit(DeleteExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(InsertExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(RenameExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(ReplaceExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(RevalidationDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(TransformExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(VarNameList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}



/* full-text-related */
bool normalize_visitor::begin_visit(FTAnd const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTAnyallOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTBigUnit const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTCaseOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTContainsExpr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTContent const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTDiacriticsOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTDistance const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTIgnoreOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTInclExclStringLiteral const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTInclExclStringLiteralList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(FTLanguageOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTMatchOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTMatchOptionProximityList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(FTMildnot const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTOptionDecl const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTOr const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTOrderedIndicator const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTProximity const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTRange const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTRefOrList const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTScope const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTScoreVar const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTSelection const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTStemOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTStopwordOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTStringLiteralList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(FTThesaurusID const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTThesaurusList const& v)
{
cout << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(FTThesaurusOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTTimes const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTUnaryNot const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTUnit const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTWildcardOption const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTWindow const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTWords const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTWordsSelection const& v)
{
cout << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(FTWordsValue const& v)
{
cout << TRACE << endl;
	return true;
}


/*..........................................
 :  end visit                              :
 :.........................................*/

void normalize_visitor::end_visit(parsenode const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(exprnode const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(AbbrevForwardStep const& v)
{
cout << indent[depth--] << TRACE << ": AbbrevForwardStep\n";
	rchandle<axis_step_expr> aexpr_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (aexpr_h==NULL) {
		cout << TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	aexpr_h->set_axis(axis_step_expr::child);
}

void normalize_visitor::end_visit(AnyKindTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(AposAttrContentList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(AposAttrValueContent const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ArgList const& v)
{
cout << indent[depth--] << TRACE << ": ArgList" << endl;
	clear_argstack();
	while (true) {
		expr_h_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		argstack.push(e_h);
	}
}

void normalize_visitor::end_visit(AtomicType const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(AttributeTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(BaseURIDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(BoundarySpaceDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CaseClause const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CaseClauseList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CommentTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ConstructionDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CopyNamespacesDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DefaultCollationDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DefaultNamespaceDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DirAttr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DirAttributeList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DirAttributeValue const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DirElemContentList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DocumentTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ElementTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(EmptyOrderDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ForClause const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ForLetClause const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ForLetClauseList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ForwardAxis const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ForwardStep const& v)
{
cout << indent[depth--] << TRACE << ": ForwardStep\n";
}

void normalize_visitor::end_visit(FunctionDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(GeneralComp const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Import const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(InheritMode const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ItemType const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(KindTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(LetClause const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(LibraryModule const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(MainModule  const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Module const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ModuleDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ModuleImport const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(NameTest const& v)
{
cout << indent[depth--]<<TRACE<<": NameTest("; v.get_qname()->put(cout,*ctx_p)<<")\n";
	rchandle<axis_step_expr> aexpr_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (aexpr_h==NULL) {
		cout << TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	aexpr_h->set_name(v.get_qname());
	aexpr_h->set_test(axis_step_expr::name_test);
	rchandle<Wildcard> wild_h = v.get_wild();
	if (wild_h==NULL) return;
	switch (wild_h->get_type()) {
	case wild_all: aexpr_h->set_wild(axis_step_expr::all_wild); break;
	case wild_elem: aexpr_h->set_wild(axis_step_expr::name_wild); break;
	case wild_prefix: aexpr_h->set_wild(axis_step_expr::prefix_wild); break;
	}
}

void normalize_visitor::end_visit(NamespaceDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(NodeComp const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(NodeTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OccurrenceIndicator const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OptionDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OrderByClause const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OrderCollationSpec const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OrderDirSpec const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OrderEmptySpec const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OrderModifier const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OrderSpec const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OrderSpecList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OrderingModeDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(PITest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Param const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ParamList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(PositionalVar const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Pragma const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(PragmaList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(PredicateList const& v)
{
cout << indent[depth--] << TRACE << ": PredicateList" << endl;
	clear_pstack();
	while (true) {
		expr_h_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		pstack.push(e_h);
	}
}

void normalize_visitor::end_visit(PreserveMode const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Prolog const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(QVarInDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(QVarInDeclList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(QuoteAttrValueContent const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(QuoteAttrContentList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ReverseAxis const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ReverseStep const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(SIND_Decl const& v)
{
cout << TRACE << endl;
	expr_h_t e_h;
	rchandle<expr_list> elist_h = new expr_list(v.get_location());
	while (true) {	
		if ((e_h = pop_nodestack())==NULL) break;
		elist_h->add(e_h);
	}
	nodestack.push(&*elist_h);
}

void normalize_visitor::end_visit(SIND_DeclList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(SchemaAttributeTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(SchemaElementTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(SchemaImport const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(SchemaPrefix const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(SequenceType const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Setter const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(SignList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(SingleType const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(TextTest const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(TypeDeclaration const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(TypeName const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(URILiteralList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ValueComp const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VarDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VarGetsDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VarGetsDeclList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VarInDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VarInDeclList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VersionDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VFO_Decl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VFO_DeclList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(WhereClause const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Wildcard const& v)
{
cout << TRACE << endl;
}




/* expressions */
void normalize_visitor::end_visit(AdditiveExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(AndExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(AxisStep const& v)
{
cout << indent[depth--] << TRACE << ": AxisStep\n";
	rchandle<axis_step_expr> aexpr_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (aexpr_h==NULL) {
		cout << TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	while (!pstack.empty()) {
		expr_h_t e_h = pstack.top();
		pstack.pop();
		aexpr_h->add_pred(e_h);
	}
}

void normalize_visitor::end_visit(CDataSection const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CastExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CastableExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CommonContent const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ComparisonExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CompAttrConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CompCommentConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CompDocConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CompElemConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CompPIConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(CompTextConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ComputedConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Constructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ContextItemExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DirCommentConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DirElemConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DirElemContent const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DirPIConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(DirectConstructor const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(EnclosedExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Expr const& v)
{
cout << indent[depth--] << TRACE << ": Expr\n";
	rchandle<expr_list> elist_h = new expr_list(v.get_location());
	while (true) {	
		expr_h_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		elist_h->add(e_h);
	}
	nodestack.push(&*elist_h);
}

void normalize_visitor::end_visit(ExprSingle const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ExtensionExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FLWORExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FilterExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FunctionCall const& v)
{
cout << indent[depth] << TRACE << ": FunctionCall" << endl;
cout << indent[depth--] << TRACE << ": argstack.size() = " << argstack.size() << endl;

	rchandle<funcall_expr> fexpr_h =
		dynamic_cast<funcall_expr*>(&*nodestack.top());
	if (fexpr_h==NULL) return;

	while (!argstack.empty()) {
		expr_h_t e_h = argstack.top();
		argstack.pop();
		if (e_h==NULL) continue;
		fexpr_h->add_arg(e_h);
	}
}

void normalize_visitor::end_visit(IfExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(InstanceofExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(IntersectExceptExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Literal const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(MultiplicativeExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(NumericLiteral const& v)
{
cout << indent[depth--] << TRACE << ": NumericLiteral" << endl;
	switch (v.get_type()) {
	case num_integer: {
		nodestack.push(new literal_expr(v.get_location(), v.get_int()));
		break;
	}
	case num_decimal: {
		nodestack.push(new literal_expr(v.get_location(), v.get_decimal()));
		break;
	}
	case num_double: {
		nodestack.push(new literal_expr(v.get_location(), v.get_double()));
		break;
	}
	}
}

void normalize_visitor::end_visit(OrExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(OrderedExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ParenthesizedExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(PathExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(Predicate const& v)
{
cout << indent[depth--] << TRACE << ": Predicate" << endl;
}

void normalize_visitor::end_visit(PrimaryExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(QuantifiedExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(QueryBody const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(RangeExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(RelativePathExpr const& v)
{
cout << indent[depth--] << TRACE << ": RelativePath\n";
	stack<expr_h_t> expr_stack;
	while (true) {
		expr_h_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		expr_stack.push(e_h);
	}
	rchandle<relpath_expr> rexpr_h = new relpath_expr(v.get_location());

	while (!expr_stack.empty()) {
		expr_h_t e_h = expr_stack.top();
		expr_stack.pop();

		// check for sub-relpath, and combine
		rchandle<relpath_expr> rexpr0_h = dynamic_cast<relpath_expr*>(&*e_h);
		if (rexpr0_h!=NULL) {
			vector<expr_h_t>::const_iterator it = rexpr0_h->begin();
			for (; it!=rexpr0_h->end(); ++it) {
				rexpr_h->add_step(*it);
			}
		}
		else {
			rexpr_h->add_step(e_h);
		}
	}
	nodestack.push(&*rexpr_h);
}

void normalize_visitor::end_visit(StepExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(StringLiteral const& v)
{
cout << indent[depth--] << TRACE << ": StringLiteral" << endl;
	off_t sid = ctx_p->put_string(v.get_strval());
	nodestack.push(new literal_expr(v.get_location(), sid, true));
}

void normalize_visitor::end_visit(TreatExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(TypeswitchExpr const& v)
{
cout << TRACE << endl;
	case_clause * cc_p;
	expr_h_t e_h;
	rchandle<typeswitch_expr> tse_h = new typeswitch_expr(v.get_location());

	rchandle<var_expr> ve_h = new var_expr(v.get_location());
	ve_h->set_varname(new QName(QName::qn_var,v.get_default_varname()));
	tse_h->set_default_varname(ve_h);

	Assert<null_pointer>((e_h = pop_nodestack())!=NULL);
	tse_h->set_switch_expr(e_h);

	Assert<null_pointer>((e_h = pop_nodestack())!=NULL);
	tse_h->set_default_clause(e_h);

	while (true) {	// pop clauses
		e_h = nodestack.top();
		if ((cc_p = dynamic_cast<case_clause*>(&*e_h))==NULL) break;
		nodestack.pop();
		tse_h->add_clause(cc_p);
	}

	nodestack.push(&*tse_h);
}

void normalize_visitor::end_visit(UnaryExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(UnionExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(UnorderedExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ValidateExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ValueExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VarRef const& v)
{
cout << TRACE << endl;
	rchandle<var_expr> ve_h = new var_expr(v.get_location());
	ve_h->set_varname(new QName(QName::qn_var,v.get_varname()));
	nodestack.push(&*ve_h);
}



/* update-related */
void normalize_visitor::end_visit(DeleteExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(InsertExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(RenameExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(ReplaceExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(RevalidationDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(TransformExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(VarNameList const& v)
{
cout << TRACE << endl;
}



/* full-text-related */
void normalize_visitor::end_visit(FTAnd const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTAnyallOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTBigUnit const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTCaseOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTContainsExpr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTContent const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTDiacriticsOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTDistance const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTIgnoreOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTInclExclStringLiteral const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTInclExclStringLiteralList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTLanguageOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTMatchOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTMatchOptionProximityList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTMildnot const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTOptionDecl const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTOr const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTOrderedIndicator const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTProximity const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTRange const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTRefOrList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTScope const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTScoreVar const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTSelection const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTStemOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTStopwordOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTStringLiteralList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTThesaurusID const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTThesaurusList const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTThesaurusOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTTimes const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTUnaryNot const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTUnit const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTWildcardOption const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTWindow const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTWords const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTWordsSelection const& v)
{
cout << TRACE << endl;
}

void normalize_visitor::end_visit(FTWordsValue const& v)
{
cout << TRACE << endl;
}


} /* namespace xqp */

