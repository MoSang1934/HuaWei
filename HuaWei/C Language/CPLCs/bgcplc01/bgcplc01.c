#include <gplib.h>
#include <stdio.h>
#include <dlfcn.h>
//----------------------------------------------------------------------------------
// pp_proj.h is the C header for accessing PMAC Global, CSGlobal, Ptr vars
// _PPScriptMode_ for Pmac Script like access global & csglobal
// _EnumMode_ for Pmac enum data type checking on Set & Get global functions
//------------------------------------------------------------------------------------
// #define _PPScriptMode_	// uncomment for Pmac Script type access
// #define _EnumMode_			// uncomment for Pmac enum data type checking on Set & Get global functions		

#include "../../Include/pp_proj.h"

void user_plcc()
{
int EMC_C,SEMC_C;
EMC_C=GetPtrVar(EMC);
SEMC_C=GetPtrVar(SEMC);
if((EMC_C==0)||(SEMC_C))
{
	AbortCoord(1);
	AbortCoord(2);
	AbortCoord(3);
	AbortCoord(0);
	SetPtrVar(STO_0,1);
	SetPtrVar(STO_1,1);

}
else
{
	SetPtrVar(STO_0,0);
	SetPtrVar(STO_1,0);
}
}



