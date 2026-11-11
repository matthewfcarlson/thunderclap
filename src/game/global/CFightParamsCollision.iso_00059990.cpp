// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00059260..0x0005a4c0 (kind game, layer game, confidence high), dominant class CFightParamsCollision
#include "tree_prelude.h"


// 0x00059990 CFightParamsCollision::vfunc_4 (98 B): equivalent/0x00059990.cpp [isolated: helper definitions (2 out-of-line function bodies); compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?vfunc_4@CFightParamsCollision@fn_ff6d7003@@UAEPAU12@XZ
namespace fn_ff6d7003 {} using namespace fn_ff6d7003;
namespace fn_ff6d7003 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// CFightParamsCollision::vfunc_4 @ 0x00059990
/* size_t: tree_prelude.h */
void* __cdecl FUN_0008d690(unsigned int);
struct CFightParamsCollision_59990 { void FUN_00236a60(); };
struct CollisionData {
    char pad0[0x4c]; unsigned int a,b;
    char pad1[0x0c]; unsigned int c;
    char pad2[0x08]; unsigned int d,e;
    char pad3[0x10]; unsigned int f;
    void FUN_00059370(CollisionData*);
};
struct CFightParamsCollision {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual CFightParamsCollision* vfunc_4();
    unsigned int unknown4;
    unsigned int value8;
    unsigned int valueC;
    unsigned int value10;
    unsigned int unknown14;
    CollisionData data;
};

} // namespace fn_ff6d7003
HULK_NATIVE_INLINE void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_ff6d7003 {

CFightParamsCollision* CFightParamsCollision::vfunc_4() {
    CFightParamsCollision* result = (CFightParamsCollision*)FUN_0008d690(0xb0);
    if (!result) return 0;
    unsigned int savedValue = value8;
    ((CFightParamsCollision_59990*)result)->FUN_00236a60();
    new (result) CFightParamsCollision;
    result->value8 = savedValue;
    result->valueC = 0;
    result->value10 = 0;
    result->data.a = 0;
    result->data.b = 0;
    result->data.c = 0;
    result->data.d = 0;
    result->data.e = 0;
    result->data.f = 0;
    result->data.FUN_00059370(&data);
    return result;
}
} // namespace fn_ff6d7003

