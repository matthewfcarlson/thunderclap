// Checker annotations (attributes only tools/equiv64.py's libclang parse sees, under HULK_EQ64_PARSE; every compiled
// build gets nothing, so no code changes). Moved here from decls/data/records.h (integ4) so include/gen can use them.
// HULK_RANGE(lo, hi), after an integer field's declarator: the values the game stores there (lo..hi), where the code
// uses the field as an index; its comment cites the writer sites. The generator draws the field from that range.
// HULK_INTO(field), after a pointer parameter's name in a member function's definition: the pointer is into the
// array this->field points to (a pool's block, from the pool's data); tools/equiv64.py generates it there.
// (D103) On a TU's redeclaration of a global (`extern "C" int DAT_0056bfc8[514] HULK_RANGE(0, 255);`, its comment
// citing the stores into it) HULK_RANGE bounds every integer word of the global. HULK_RDATA, after a const global's
// declarator: a table in a read-only section of the XBE; tools/equiv64.py starts both runs from its bytes there.
// (integ4, x64bounds) HULK_COUNT(field), after a pointer field's declarator: it points at an array of exactly
// this->field elements of its pointee type; HULK_COUNT_BYTES(field, n) the same for a void pointer, elements of n
// bytes. The count field carries a cited HULK_RANGE and the pointer field's comment cites its writers.
#ifndef HULK_ANNOT_H
#define HULK_ANNOT_H
#if defined(HULK_EQ64_PARSE)
#define HULK_RANGE(lo, hi) __attribute__((annotate("hulk_range " #lo " " #hi)))
#define HULK_INTO(field) __attribute__((annotate("hulk_into " #field)))
#define HULK_RDATA __attribute__((annotate("hulk_rdata")))
#define HULK_COUNT(field) __attribute__((annotate("hulk_count " #field)))
#define HULK_COUNT_BYTES(field, n) __attribute__((annotate("hulk_count " #field " " #n)))
#else
#define HULK_RANGE(lo, hi)
#define HULK_INTO(field)
#define HULK_RDATA
#define HULK_COUNT(field)
#define HULK_COUNT_BYTES(field, n)
#endif
#endif
