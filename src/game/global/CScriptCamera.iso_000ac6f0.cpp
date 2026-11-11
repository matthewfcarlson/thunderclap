// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ac610..0x000acda0 (kind game, layer game, confidence high), dominant class CScriptCamera
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x000ac6f0 FUN_000ac6f0 (132 B): equivalent/0x000ac6f0.cpp [isolated: code differs from its standalone build]
// sym: ?Evaluate@Curve_ac6f0@fn_ffe158fd@@QAEMMM@Z @f15afacbe95a @w5727c622ab68
#include "gen/owners.h"
namespace fn_ffe158fd {} using namespace fn_ffe158fd;
namespace fn_ffe158fd {
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 12/12)
// FUN_000ac6f0 @ 0x000ac6f0
// FUN_000ac6f0 @ 0x000ac6f0
struct ThisCall_000ac6a0 {
    hulk_freg FUN_000ac6a0(float t);
};

class Curve_ac6f0 {
public:
    char mode;
    char pad01[3];
    float constant;
    float start;
    float length;
    char pad10[4];
    float before;
    float after;
    char dirty;
    hulk_freg Evaluate(float t, float end);
};

hulk_freg Curve_ac6f0::Evaluate(float t, float end)
{
    if (mode == 0)
        return constant;
    if (dirty) {
        ((owners::Thing_ac610 *)this)->FUN_000ac610();
        dirty = 0;
    }
    if (length < 0.01f || length > end)
        length = end - start;
    if (start >= t)
        return before;
    if (start + length <= t)
        return after;
    return ((ThisCall_000ac6a0*)(this))->FUN_000ac6a0((t - start) / length);
}
} // namespace fn_ffe158fd

