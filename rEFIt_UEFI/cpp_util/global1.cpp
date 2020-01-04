#include "XStringW.h"
XStringW global_str1(L"global_str1");

extern "C" void __GLOBAL__sub_I_global1()
{
	#ifdef __clang__
	  asm("call __GLOBAL__sub_I_global1.cpp");
	#endif
}
