/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: charheap.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *
 */

#ifndef XQP_FXCHARHEAP_H
#define XQP_FXCHARHEAP_H

#include "fxarray.h"
#include "xqpexception.h"

namespace xqp {

class fxcharheap
{

public:  //iterator 

  typedef class fxcharheap_iterator
  {
    char const* _begin;
    char const* _end;
    char * current;
    fxcharheap const* parent;

  public:	//ctor,dtor
    fxcharheap_iterator(fxcharheap * ch, uint32_t initial_offset);
    ~fxcharheap_iterator();

	public:	//iterator interface
    char const* operator++();
    char const* operator*() const;

		friend bool operator!=(fxcharheap_iterator const&, fxcharheap_iterator const&);

  } const_iterator;

	const_iterator begin();
	const_iterator end();


public:	//state
	fxarray<char> * fxary_p;		// flex-array, either in-memory or memory-mapped
	char * data;								// heap data
  off_t * offset_p;   				// pointer to offset to first unused char 


public:	//ctor,dtor
	/**
	 **	Create memory-mapped char heap.
	 */
  fxcharheap(std::string const& path, uint32_t initial_size);

	/**
	 **	Create in-memory char heap.
	 */
  fxcharheap(uint32_t initial_size);

	/**
	 **	Destroy char heap.
	 */
  ~fxcharheap();


public:  //heap interface
	/**
	 ** Get a block of characters, placing into given output array.
	 */
  void get(
    off_t id,								// input: heap offset
    char * buf,							// output: output buffer
    uint32_t offset,				// input: buffer starting offset
    uint32_t maxlen) const	// input: maximum output size, truncate
	throw (xqp::xqpexception);

	/**
   ** Insert a new block of characters.
	 **
   **	@return byte offset of the new string entry
   **	@note occasionally expensive, doubling the heap if needed.
	 */
  off_t put(
    char const* buf,				// input: string
    uint32_t offset,				// input: starting offset
    uint32_t len)						// input: string length
	throw (xqp::xqpexception);

	/**
   **	Replace a block of characters in place.
	 */
  void replace(
		off_t id,								// input: heap offset
    char const* buf,        // input: string
    uint32_t offset,				// input: starting offset
    uint32_t len)						// input: string length
	throw (xqp::xqpexception);

	/**
   **	Return the length of the string at offset 'id'.
	 **
	 **	@return length
	 */
  uint32_t get_length(off_t id) const;

	/**
   **	Return the heap capacity.
	 **
	 **	@return currently allocated capacity
	 */
  uint64_t capacity() const { return fxary_p->size() - sizeof(off_t); }

	/**
	 **	Return the heap size.
	 **
   **	@return current heap size in bytes
	 */
  uint64_t size() const { return *offset_p - sizeof(off_t); }


protected:	//internals
	/**
	 ** common initialization
	 */
	void init();

	/**
   **	double the heap
	 */
  void expand();

	/**
   **	parametrized io exception
	 */
	void ioexception(std::string const& location, std::string const& msg) const; 

};


}  /* namespace xqp */
#endif  /* XQP_FXCHARHEAP_H */
