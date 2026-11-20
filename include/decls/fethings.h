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

// HULK_FE_SPAN(start, end): a pad from 32-bit offset `start` to `end` in a view of FEThings: the literal on MSVC, the
// distance between the two offsets' native places in gen's layout on clang (HULK_FE_N maps a 32-bit offset: scaled by
// HULK_FE_P over the pointer tables and pointer members, unchanged across the words between them). (recs1)
#if defined(__clang__)
#define HULK_FE_O(f) __builtin_offsetof(::FEThings, f)
#define HULK_FE_P (sizeof(void*) / 4)   // 1 on the 32-bit clang (Wine) build, 2 natively
#define HULK_FE_N(k) ( \
    (k) <= 0x170c ? (k) * HULK_FE_P : \
    (k) < 0x175c ? HULK_FE_O(f_170c) + ((k) - 0x170c) : \
    (k) <= 0x1764 ? HULK_FE_O(f_175c) + ((k) - 0x175c) * HULK_FE_P : \
    (k) < 0x1768 ? HULK_FE_O(f_175c) + 0x8 * HULK_FE_P + ((k) - 0x1764) : \
    (k) <= 0x176c ? HULK_FE_O(f_1768) + ((k) - 0x1768) * HULK_FE_P : \
    (k) < 0x17fc ? HULK_FE_O(f_1768) + 0x4 * HULK_FE_P + ((k) - 0x176c) : \
    (k) <= 0x1800 ? HULK_FE_O(f_17fc) + ((k) - 0x17fc) * HULK_FE_P : \
    (k) < 0x1818 ? HULK_FE_O(f_17fc) + 0x4 * HULK_FE_P + ((k) - 0x1800) : \
    (k) <= 0x181c ? HULK_FE_O(f_1818) + ((k) - 0x1818) * HULK_FE_P : \
    (k) < 0x1828 ? HULK_FE_O(f_1818) + 0x4 * HULK_FE_P + ((k) - 0x181c) : \
    (k) <= 0x1830 ? HULK_FE_O(f_1828) + ((k) - 0x1828) * HULK_FE_P : \
    (k) < 0x183c ? HULK_FE_O(f_1828) + 0x8 * HULK_FE_P + ((k) - 0x1830) : \
    (k) <= 0x1840 ? HULK_FE_O(f_183c) + ((k) - 0x183c) * HULK_FE_P : \
    (k) < 0x1854 ? HULK_FE_O(f_183c) + 0x4 * HULK_FE_P + ((k) - 0x1840) : \
    (k) <= 0x185c ? HULK_FE_O(f_1854) + ((k) - 0x1854) * HULK_FE_P : \
    (k) < 0x1a5c ? HULK_FE_O(f_1854) + 0x8 * HULK_FE_P + ((k) - 0x185c) : \
    (k) <= 0x1a64 ? HULK_FE_O(f_1a5c) + ((k) - 0x1a5c) * HULK_FE_P : \
    (k) < 0x1c64 ? HULK_FE_O(f_1a5c) + 0x8 * HULK_FE_P + ((k) - 0x1a64) : \
    (k) <= 0x1c74 ? HULK_FE_O(f_1c64) + ((k) - 0x1c64) * HULK_FE_P : \
    (k) < 0x2078 ? HULK_FE_O(f_1c64) + 0x10 * HULK_FE_P + ((k) - 0x1c74) : \
    (k) <= 0x2100 ? HULK_FE_O(f_2078) + ((k) - 0x2078) * HULK_FE_P : \
    (k) < 0x220c ? HULK_FE_O(f_2078) + 0x88 * HULK_FE_P + ((k) - 0x2100) : \
    (k) <= 0x2210 ? HULK_FE_O(f_220c) + ((k) - 0x220c) * HULK_FE_P : \
    (k) < 0x2218 ? HULK_FE_O(f_220c) + 0x4 * HULK_FE_P + ((k) - 0x2210) : \
    (k) <= 0x221c ? HULK_FE_O(f_2218) + ((k) - 0x2218) * HULK_FE_P : \
    (k) < 0x2224 ? HULK_FE_O(f_2218) + 0x4 * HULK_FE_P + ((k) - 0x221c) : \
    (k) <= 0x2228 ? HULK_FE_O(f_2224) + ((k) - 0x2224) * HULK_FE_P : \
    (k) < 0x2230 ? HULK_FE_O(f_2224) + 0x4 * HULK_FE_P + ((k) - 0x2228) : \
    (k) <= 0x2238 ? HULK_FE_O(f_2230) + ((k) - 0x2230) * HULK_FE_P : \
    HULK_FE_O(f_2230) + 0x8 * HULK_FE_P + ((k) - 0x2238))
#define HULK_FE_SPAN(s, e) (HULK_FE_N(e) - HULK_FE_N(s))
#else
#define HULK_FE_SPAN(s, e) ((e) - (s))
#endif

#endif
