//@doc
//@class    AAFNestedScope | Implementation class for AAFNestedScope
#ifndef __ImplAAFNestedScope_h__
#define __ImplAAFNestedScope_h__


/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
*                                          *
\******************************************/


#ifndef __AAFTypes_h__
#include "AAFTypes.h"
#endif

/*************************************************************************
 * 
 * @class AAFNestedScope | an AAFNestedScope object defines a scope that 
 *			contains an ordered set of AAFSegments and produces the value
 *			specified by the last AAFSegement in the ordered set.
 *
 * @base public | AAFSegment
 *
 *************************************************************************/

#ifndef __ImplAAFSegment_h__
#include "ImplAAFSegment.h"
#endif

class ImplEnumAAFSegments;






#ifndef __ImplAAFSegment_h__
#include "ImplAAFSegment.h"
#endif


class ImplAAFNestedScope : public ImplAAFSegment
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFNestedScope ();

protected:
  virtual ~ImplAAFNestedScope ();

public:


  //****************
  // AppendSegment()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    AppendSegment
        // @parm [in] Pointer to segment to be added
        (ImplAAFSegment * pSegment);

  //****************
  // RemoveSegment()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RemoveSegment
        // @parm [in] Pointer to segment to be added
        (ImplAAFSegment * pSegment);

  //****************
  // GetSlots()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetSlots
        // @parm [retval][out] Slots - segment list  enumeration
        (ImplEnumAAFSegments ** ppEnum);

public:
	// SDK-internal

	virtual AAFRESULT ChangeContainedReferences(aafUID_t *from, aafUID_t *to);


private:

  // Persistent Properties	
  OMStrongReferenceVectorProperty<ImplAAFSegment>		_slots;
};

#endif // ! __ImplAAFNestedScope_h__


