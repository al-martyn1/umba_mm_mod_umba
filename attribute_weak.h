#pragma once

#include "umba.h"

/*
  Список weak функций C++ (new/delete) - https://stackoverflow.com/questions/15525537/what-are-practical-applications-of-weak-linking
  GCC __attribute__((weak));
      int __attribute__((weak)) power2(int x);
      int power2(int x) __attribute__((weak));
      --whole-archive
      https://maskray.me/blog/2021-04-25-weak-symbol
  MSVC __declspec(selectany) - https://stackoverflow.com/questions/2290587/gcc-style-weak-linking-in-visual-studio/11529277#11529277
  https://devblogs.microsoft.com/oldnewthing/20160317-00/?p=93173
  https://devblogs.microsoft.com/oldnewthing/20200731-00/?p=104024
  https://ofekshilon.com/2014/02/10/linker-weak-symbols/

  CLANG - https://clang.llvm.org/docs/AttributeReference.html#weak
          https://clang.llvm.org/docs/AttributeReference.html#selectany

          Вообще по шланговским атрибутам - https://clang.llvm.org/docs/AttributeReference.html

  Wiki - https://en.wikipedia.org/wiki/Weak_symbol

*/

#if defined(UMBA_MSVC_COMPILER_USED)

    #define UMBA_ATTRIBUTE_WEAK    /* __declspec(selectany) */

#elif defined(UMBA_GCC_COMPILER_USED)

    #define UMBA_ATTRIBUTE_WEAK    __attribute__((weak))

// #elif defined(UMBA_CLANG_COMPILER_USED) // Clang works as MSVC or GCC

#else

    // #error "UMBA_ATTRIBUTE_WEAK not defined"
    // #define UMBA_ATTRIBUTE_WEAK

#endif

