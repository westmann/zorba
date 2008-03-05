/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: tracer.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef ZORBA_TRACER_H
#define ZORBA_TRACER_H

namespace zorba {

#ifndef WIN32
#define TRACE __FILE__<<':'<<__LINE__<<"::"<<__PRETTY_FUNCTION__
#define LOCATION	(__oss.str(""), \
										__oss<<__FILE__<<":"<<__LINE__<<"::"<<__PRETTY_FUNCTION__, \
										__oss.str())
#else
#define TRACE __FILE__<<':'<<__LINE__<<"::"<<__FUNCTION__
#define LOCATION	(__oss.str(""), \
										__oss<<__FILE__<<":"<<__LINE__<<"::"<<__FUNCTION__, \
										__oss.str())

#endif

} /* namespace zorba */
#endif /* ZORBA_TRACER_H */

