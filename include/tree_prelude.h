// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// Included first by every TU of the tree (docs/native-build.md fix 1).
#ifndef TREE_PRELUDE_H
#define TREE_PRELUDE_H
#if defined(__SIZE_TYPE__)
typedef __SIZE_TYPE__ size_t;          /* clang, any target */
#else
/* size_t: tree_prelude.h */           /* MSVC 7.1 (predeclares the same type) */
#endif
/* the exception specification of the global `operator new(size_t)` a TU declares: MSVC null-checks the
   result of a throw() new (codegen depends on it); non-MS targets declare it implicitly without one, so
   the native build drops it there and compiles with -fcheck-new instead */
#if defined(_MSC_VER)
#define HULK_NEW_THROW throw()
#else
#define HULK_NEW_THROW
#endif
/* global operator new/delete definitions that several TUs repeat (the placement new): `inline` for the
   native build, so its link keeps one; nothing under MSVC 7.1 (/Ob1 would inline them into callers) */
#if defined(_MSC_VER) && !defined(__clang__)
#define HULK_NATIVE_INLINE
#else
#define HULK_NATIVE_INLINE inline
#endif
#endif
