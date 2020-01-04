#include "XStringW.h"
XStringW global_str2(L"global_str2");

extern "C" void __GLOBAL__sub_I_global2()
{
	#ifdef __clang__
	  asm("call __GLOBAL__sub_I_global2.cpp");
	#endif
}
