//@doc
//@class    AAFEssenceGroup | Implementation class for AAFEssenceGroup
#ifndef __ImplAAFEssenceGroup_h__
#define __ImplAAFEssenceGroup_h__


/***********************************************************************
 *
 *              Copyright (c) 1998-1999 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and accompanying 
 * documentation, and to distribute and sublicense application software
 * incorporating this software for any purpose is hereby granted, 
 * provided that (i) the above copyright notice and this permission
 * notice appear in all copies of the software and related documentation,
 * and (ii) the name Avid Technology, Inc. may not be used in any
 * advertising or publicity relating to the software without the specific,
 *  prior written permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
 * OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
 * ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
 * ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
 * LIABILITY.
 *
 ************************************************************************/


/***********************************************\
*	Stub only.   Implementation not yet added	*
\***********************************************/



class ImplAAFSegment;

class ImplAAFDataDef;

class ImplAAFSourceClip;

#ifndef __ImplAAFSegment_h__
#include "ImplAAFSegment.h"
#endif

#include "OMStrongRefProperty.h"
#include "OMStrongRefVectorProperty.h"

class ImplAAFEssenceGroup : public ImplAAFSegment
{
public:
  //
  // Constructor/destructor
  //
  //********
  ImplAAFEssenceGroup ();

protected:
  virtual ~ImplAAFEssenceGroup ();

public:



  //****************
  // SetStillFrame()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    SetStillFrame
        // @parm [in] Still Frame source clip 
        (ImplAAFSourceClip * stillFrame);
    //@comm Essence group choices should be added with the AddChoice() function.
    

  //****************
  // GetStillFrame()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetStillFrame
        // @parm [out] Still Frame source clip 
        (ImplAAFSourceClip **stillFrame);
    //@comm Essence group choices should be added with the AddChoice() function.
    

  //****************
  // AppendChoice()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    AppendChoice
        // @parm [in] Source clip to add as a choice 
        (ImplAAFSegment * choice);


  //****************
  // PrependChoice()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    PrependChoice
        // @parm [in] Source clip to add as a choice 
        (ImplAAFSegment * choice);


  //****************
  // InsertChoiceAt()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    InsertChoiceAt
        // @parm [in] place to put new choice
        (aafUInt32 index,

		 // @parm [in] Source clip to add as a choice
		 ImplAAFSegment * choice);


  //****************
  // CountChoices()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    CountChoices
        (aafUInt32  *result);


  //****************
  // GetChoiceAt()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    GetChoiceAt
        (// @parm [in] The 0-based index into the array
         aafUInt32  index,

         // @parm [out] The representation at that index
         ImplAAFSegment  ** result);


  //****************
  // RemoveChoiceAt()
  //
  virtual AAFRESULT STDMETHODCALLTYPE
    RemoveChoiceAt
        (// @parm [in] The 0-based index into the array
         aafUInt32  index);

public:
	//SDK-private methods
	AAFRESULT GetMinimumBounds(aafPosition_t rootPos, aafLength_t rootLen,
										ImplAAFMob *mob, ImplAAFMobSlot *track,
										aafMediaCriteria_t *mediaCrit,
										aafPosition_t currentObjPos,
										aafOperationChoice_t *effectChoice,
										ImplAAFComponent	*prevObject,
										ImplAAFComponent *nextObject,
										ImplAAFScopeStack *scopeStack,
										aafPosition_t *diffPos, aafLength_t *minLength,
										ImplAAFOperationGroup **effeObject, aafInt32	*nestDepth,
										ImplAAFComponent **foundObj, aafBool *foundTransition);

	AAFRESULT GetCriteriaSegment(
			aafMediaCriteria_t *criteria,
			ImplAAFSegment		**retSrcClip);

private:
	OMStrongReferenceVectorProperty<ImplAAFSegment>	_choices;
	OMStrongReferenceProperty<ImplAAFSourceClip>		_stillFrame;
};	

#endif // ! __ImplAAFEssenceGroup_h__
