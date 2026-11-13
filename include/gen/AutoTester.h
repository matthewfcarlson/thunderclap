// Class declarations from the game's RTTI. Source, edited by hand (tools/gen_headers.py generated them until
// gen1, 2026-11-13). vfunc_N = slot N of the class that introduced it; fields only where code proves the offset.
// tools/gen_headers.py --probe checks the layouts against RTTI and the XBE. See docs/headers.md.

#ifndef HULK_GEN_AUTOTESTER_H
#define HULK_GEN_AUTOTESTER_H

#include "_prelude.h"
// Forward declarations
namespace AutoTester {
struct IMessageScriptCallback;
} // namespace AutoTester

namespace AutoTester {
// .?AUIMessageScriptCallback@AutoTester@@  vftable 0x400ec0 (1)
struct IMessageScriptCallback {
public:
    virtual void vfunc_0(int, int) = 0; // slot 0
};

} // namespace AutoTester

#endif // HULK_GEN_AUTOTESTER_H
