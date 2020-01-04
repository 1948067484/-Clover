//===-- crtbegin.c - Start of constructors and destructors ----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#if 0
#define DBG(...) DebugLog(2, __VA_ARGS__)
#else
#define DBG(...)
#endif


extern "C" {
  #include <stddef.h>
}

#include <Platform/Platform.h>



typedef void (ctor)(void);
typedef ctor* ctor_ptr;

#if defined(__clang__)


void construct_globals_objects()
{
	// __GLOBAL__sub_I_[module name] has to be called from main
}

#elif defined(__GNUC__)

__attribute__((visibility("hidden"))) void *__dso_handle = &__dso_handle;

extern int __beginning_of_section_ctors, __end_of_section_ctors;

ctor_ptr* p = (ctor_ptr*)&__beginning_of_section_ctors;
ctor_ptr* pend = (ctor_ptr*)&__end_of_section_ctors;


void construct_globals_objects() {
    DBG("CTOR %x %d\n", (UINTN)p, (UINTN)p);
    while ( p < pend ) {
    	DBG("CTOR %x %d\n", (UINTN)p[0], (UINTN)p[0]);
    	(*p)();
    	p++;
    }
}

#else
#error compiler nbot supported.
#endif
