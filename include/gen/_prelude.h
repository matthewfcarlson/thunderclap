#include "compat/ptr.h"
// Class declarations from the game's RTTI. Source, edited by hand (tools/gen_headers.py generated them until
// gen1, 2026-11-13). vfunc_N = slot N of the class that introduced it; fields only where code proves the offset.
// tools/gen_headers.py --probe checks the layouts against RTTI and the XBE. See docs/headers.md.
#ifndef HULK_GEN_PRELUDE_H
#define HULK_GEN_PRELUDE_H
// Classes without RTTI are only forward-declared. The game's layouts (e.g. Method1<T,...>'s
// 4-byte member-function pointer) show they use the single-inheritance member-pointer model,
// which MSVC can't infer for an incomplete class without this keyword.
#if defined(_MSC_VER) || defined(__clang__)
#define HULK_SINGLE_INHERITANCE __single_inheritance
#else
#define HULK_SINGLE_INHERITANCE
#endif
#endif
