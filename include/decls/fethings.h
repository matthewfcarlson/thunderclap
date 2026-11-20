// (recs1, find1 B3, find2 G8 / G12) Views of FEThings / FEThingsBase (gen/global.h: the callback tables, poolB and five
// widget tables of pointers from +0x0c, 0x2224 / 0x2238 bytes on the 32-bit builds). A TU's own view of the object
// pads to gen's members, not to their 32-bit offsets: `char pad[HULK_FE_PAD(f_175c, 0x175c, start)]` is the 32-bit
// literal on the MSVC build (the same code) and the distance to gen's member natively, where `start` is where the pad
// begins (another HULK_FE_PAD(member, k, 0) plus the size of what follows it). Needs gen/global.h. Only the TUs that
// view FEThings include this header (D74). Declare no namespaces here.
#ifndef HULK_DECLS_FETHINGS_H
#define HULK_DECLS_FETHINGS_H

#if defined(__clang__)
#define HULK_FE_PAD(f, k, b) (__builtin_offsetof(::FEThings, f) - (b))
#else
#define HULK_FE_PAD(f, k, b) ((k) - (b))
#endif

#endif
