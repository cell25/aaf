############################################
#                                          #
# Copyright (c) 1998 Avid Technology, Inc. #
#                                          #
############################################

all : depend.mk


BLD_CFG_DIR = ../ref-impl/bld_cfg

include $(BLD_CFG_DIR)/common.mk


# Include the file that lists all of the dodo target names.
include aafobjects.mk


depend.mk : aafobjects.mk
	@echo Creating depend.tmp ...
	@$(SH_PREFIX) rm -f depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo # This file automatically generated make. > depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo # Special case AAFTypes since no object is to be built only headers... >> depend.tmp $(SH_SUFFIX)
	@echo AAFTypes.all...
	@$(SH_PREFIX) echo AAFTypes.all : AAFTypes.cpp AAFTypes.h AAFTypes.cppt >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFTypes.all : AAFTypes.comc AAFTypes.comh >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFTypes.all : AAFTypes.implc AAFTypes.implh >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFTypes.all : AAFTypes.idl AAFTypes.exp >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFTypes.h : macros/h.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFTypes.comh : macros/comh.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFTypes.implh : macros/implh.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFTypes.idl : macros/idl.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFTypes.exp : macros/exp.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo # >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo # >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo #special case the utility classes since they will not be exposed by com >> depend.tmp $(SH_SUFFIX)
	@echo AAFUInt64.all...
	@$(SH_PREFIX) echo AAFUInt64.all : AAFUInt64.cpp AAFUInt64.h AAFUInt64.cppt >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFUInt64.all : AAFUInt64.implc AAFUInt64.implh >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFUInt64.all : AAFUInt64.exp >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFUInt64.cpp : macros/cpp.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFUInt64.h : macros/h.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFUInt64.cppt : macros/cppt.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFUInt64.implc : macros/implc.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFUInt64.implh : macros/implh.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFUInt64.exp : macros/exp.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo # >> depend.tmp $(SH_SUFFIX)
	@echo AAFInt64.all...
	@$(SH_PREFIX) echo AAFInt64.all : AAFInt64.cpp AAFInt64.h AAFInt64.cppt >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFInt64.all : AAFInt64.implc AAFInt64.implh >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFInt64.all : AAFInt64.exp >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFInt64.cpp : macros/cpp.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFInt64.h : macros/h.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFInt64.cppt : macros/cppt.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFInt64.implc : macros/implc.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFInt64.implh : macros/implh.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFInt64.exp : macros/exp.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo # >> depend.tmp $(SH_SUFFIX)
	@echo AAFString.all...
	@$(SH_PREFIX) echo AAFString.all : AAFString.cpp AAFString.h AAFString.cppt >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFString.all : AAFString.implc AAFString.implh >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFString.all : AAFString.exp >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFString.cpp : macros/cpp.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFString.h : macros/h.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFString.cppt : macros/cppt.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFString.implc : macros/implc.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFString.implh : macros/implh.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) echo AAFString.exp : macros/exp.mac macros/base.mac >> depend.tmp $(SH_SUFFIX)
	@$(SH_PREFIX) for base in $(DODO_TARGET_NAMES) ; do \
		echo $$base.all... ; \
		echo '' >> depend.tmp ; \
		echo $$base.all : $$base.cpp $$base.h $$base.cppt >> depend.tmp ; \
		echo $$base.all : $$base.comc $$base.comh $$base.comt >> depend.tmp ; \
		echo $$base.all : $$base.implc $$base.implh >> depend.tmp ; \
		echo $$base.all : $$base.idl $$base.exp >> depend.tmp ; \
		echo $$base.cpp : macros/cpp.mac macros/base.mac >> depend.tmp ; \
		echo $$base.h : macros/h.mac macros/base.mac >> depend.tmp ; \
		echo $$base.cppt : macros/cppt.mac macros/base.mac >> depend.tmp ; \
		echo $$base.comc : macros/comc.mac macros/base.mac >> depend.tmp ; \
		echo $$base.comh : macros/comh.mac macros/base.mac >> depend.tmp ; \
		echo $$base.comt : macros/comt.mac macros/base.mac >> depend.tmp ; \
		echo $$base.implc : macros/implc.mac macros/base.mac >> depend.tmp ; \
		echo $$base.implh : macros/implh.mac macros/base.mac >> depend.tmp ; \
		echo $$base.idl : macros/idl.mac macros/base.mac >> depend.tmp ; \
		echo $$base.exp : macros/exp.mac macros/base.mac >> depend.tmp ; \
		for import in `grep '^#import' $$base.dod | sed -e 's,#import,,' | sed -e 's,.*/,,'` ; do \
			echo $$base.cpp : $$import >> depend.tmp ; \
			echo $$base.h : $$import >> depend.tmp ; \
			echo $$base.cppt : $$import >> depend.tmp ; \
			echo $$base.comc : $$import >> depend.tmp ; \
			echo $$base.comh : $$import >> depend.tmp ; \
			echo $$base.comt : $$import >> depend.tmp ; \
			echo $$base.implc : $$import >> depend.tmp ; \
			echo $$base.implh : $$import >> depend.tmp ; \
			echo $$base.idl : $$import >> depend.tmp ; \
			echo $$base.exp : $$import >> depend.tmp ; \
		done ; \
	done $(SH_SUFFIX)
	@$(SH_PREFIX) echo \\n>> depend.tmp $(SH_SUFFIX)
	$(SH_PREFIX) mv depend.tmp depend.mk $(SH_SUFFIX)
	@echo "Done with depend.mk."


clean :
	$(SH_PREFIX) $(RM) -rf depend.mk $(SH_SUFFIX)
