/***********************************************\
*                                               *
* Advanced Authoring Format                     *
*                                               *
* Copyright (c) 1998-1999 Avid Technology, Inc. *
*                                               *
\***********************************************/


#ifndef __ImplAAFPropertyDef_h__
#include "ImplAAFPropertyDef.h"
#endif

#ifndef __ImplEnumAAFPropertyDefs_h__
#include "ImplEnumAAFPropertyDefs.h"
#endif

#include <assert.h>
#include <string.h>
#include "aafErr.h"
#include "AAFResult.h"
#include "ImplAAFObjectCreation.h"
#include "ImplAAFHeader.h"
#include "ImplAAFDictionary.h"

extern "C" const aafClassID_t CLSID_EnumAAFPropertyDefs;

ImplEnumAAFPropertyDefs::ImplEnumAAFPropertyDefs ()
{
	_current = 0;
	_enumObj = NULL;
	_enumStrongProp = NULL;
}


ImplEnumAAFPropertyDefs::~ImplEnumAAFPropertyDefs ()
{
	if (_enumObj)
	{
		_enumObj->ReleaseReference();
		_enumObj = NULL;
	}
}


AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFPropertyDefs::NextOne (
      ImplAAFPropertyDef **ppPropertyDef)
{
	aafUInt32			numElem;
	ImplAAFHeader		*head = NULL;
	ImplAAFDictionary	*dict = NULL;

	if(_enumStrongProp != NULL)
	{
		size_t	siz;
		
		_enumStrongProp->getSize(siz);
		numElem = siz;
	}
	else
		return(AAFRESULT_INCONSISTANCY);

	if(ppPropertyDef == NULL)
		return(AAFRESULT_NULL_PARAM);
	if(_current >= numElem)
		return AAFRESULT_NO_MORE_OBJECTS;
	XPROTECT()
	{
		if(_enumStrongProp != NULL)
			_enumStrongProp->getValueAt(*ppPropertyDef, _current);
		else
			RAISE(AAFRESULT_INCONSISTANCY);
		(*ppPropertyDef)->AcquireReference();
		_current++;
		if (head) {
			head->ReleaseReference();
			head = NULL;
		}
		if (dict) {
			dict->ReleaseReference();
			dict = NULL;
		}
	}
	XEXCEPT
	{
		if(head)
		  head->ReleaseReference();
		head = 0;
		if(dict)
		  dict->ReleaseReference();
		dict = 0;
	}
	XEND;

	return(AAFRESULT_SUCCESS); 
}


AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFPropertyDefs::Next (
      aafUInt32  count,
      ImplAAFPropertyDef **ppPropertyDefs,
      aafUInt32 *pFetched)
{
	ImplAAFPropertyDef**	ppDef;
	aafUInt32			numDefs;
	HRESULT				hr;

	if ((pFetched == NULL && count != 1) || (pFetched != NULL && count == 1))
		return E_INVALIDARG;

	// Point at the first component in the array.
	ppDef = ppPropertyDefs;
	for (numDefs = 0; numDefs < count; numDefs++)
	{
		hr = NextOne(ppDef);
		if (FAILED(hr))
			break;

		// Point at the next component in the array.  This
		// will increment off the end of the array when
		// numComps == count-1, but the for loop should
		// prevent access to this location.
		ppDef++;
	}
	
	if (pFetched)
		*pFetched = numDefs;

	return hr;
}


AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFPropertyDefs::Skip (
      aafUInt32  count)
{
	AAFRESULT	hr;
	aafUInt32	newCurrent;
	aafUInt32	numElem;
	if(_enumStrongProp != NULL)
	{
		size_t	siz;
		
		_enumStrongProp->getSize(siz);
		numElem = siz;
	}
	else
		return(AAFRESULT_INCONSISTANCY);

	newCurrent = _current + count;

	if(newCurrent < numElem)
	{
		_current = newCurrent;
		hr = AAFRESULT_SUCCESS;
	}
	else
	{
		hr = E_FAIL;
	}

	return hr;
}


AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFPropertyDefs::Reset ()
{
	_current = 0;
	return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFPropertyDefs::Clone (
      ImplEnumAAFPropertyDefs **ppEnum)
{
	ImplEnumAAFPropertyDefs	*result;
	AAFRESULT				hr;

	result = (ImplEnumAAFPropertyDefs *)CreateImpl(CLSID_EnumAAFPropertyDefs);
	if (result == NULL)
		return E_FAIL;

	if(_enumStrongProp != NULL)
		hr = result->SetEnumStrongProperty(_enumObj, _enumStrongProp);
	else
		return(AAFRESULT_INCONSISTANCY);

	if (SUCCEEDED(hr))
	{
		result->_current = _current;
		*ppEnum = result;
	}
	else
	{
	  result->ReleaseReference();
	  result = 0;
	  *ppEnum = NULL;
	}
	
	return hr;
}



AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFPropertyDefs::SetEnumStrongProperty( ImplAAFObject *pObj, propertyDefStrongRefArrayProp_t *pProp)
{
	if (_enumObj)
	  _enumObj->ReleaseReference();
	_enumObj = 0;
	_enumObj = pObj;
	if (pObj)
		pObj->AcquireReference();
	/**/
	_enumStrongProp = pProp;				// Don't refcount, same lifetime as the object.

	return AAFRESULT_SUCCESS;
}
