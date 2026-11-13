// Class declarations from the game's RTTI. Source, edited by hand (tools/gen_headers.py generated them until
// gen1, 2026-11-13). vfunc_N = slot N of the class that introduced it; fields only where code proves the offset.
// tools/gen_headers.py --probe checks the layouts against RTTI and the XBE. See docs/headers.md.

#ifndef HULK_GEN_TOKENIZER_H
#define HULK_GEN_TOKENIZER_H

#include "_prelude.h"
// Forward declarations
namespace Tokenizer {
class Stream;
} // namespace Tokenizer

namespace Tokenizer {
// .?AVStream@Tokenizer@@  vftable 0x424fd8 (5)
class Stream {
public:
    virtual ~Stream(); // slot 0
    virtual bool vfunc_1(void*) = 0; // slot 1
    virtual void vfunc_2() = 0; // slot 2
    virtual int vfunc_3(void*, int) = 0; // slot 3
    virtual bool vfunc_4() = 0; // slot 4
};

} // namespace Tokenizer

#endif // HULK_GEN_TOKENIZER_H
