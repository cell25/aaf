//=---------------------------------------------------------------------=
//
// $Id$ $Name$
//
// The contents of this file are subject to the AAF SDK Public
// Source License Agreement (the "License"); You may not use this file
// except in compliance with the License.  The License is available in
// AAFSDKPSL.TXT, or you may obtain a copy of the License from the AAF
// Association or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.
//
// The Original Code of this file is Copyright 1998-2005, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

#ifndef __CAAFModuleTest_h__
#define __CAAFModuleTest_h__

#include "AAFTypes.h"
#include "ModuleTest.h"

class CAAFModuleTest
{
public:
  CAAFModuleTest();
  ~CAAFModuleTest();
    
  //
  // Print out a list of AAF class names, one per line, in the order that 
  // the tests will be run.
  //
  void List(void);

  //
  // Call  Module test functions.
  //
  HRESULT Test(testMode_t mode,
               aafUID_t pFileKind,
               testRawStorageType_t rawStorageType,
               bool filter = false, 
               int argc = 0, 
               const char **argv = NULL);

};



#endif // __CAAFModuleTest_h__
