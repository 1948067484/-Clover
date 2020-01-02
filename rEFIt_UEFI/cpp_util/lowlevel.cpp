extern "C" {
#include <Platform/Platform.h>
}

#if 1
#define DBG(...) DebugLog(2, __VA_ARGS__)
#else
#define DBG(...)
#endif


void* operator new  ( unsigned long count )
{
	return AllocatePool(count);
}

void operator delete  ( void* ptr )
#ifdef __clang__
                                     noexcept
#endif
{
	return FreePool(ptr);
}







