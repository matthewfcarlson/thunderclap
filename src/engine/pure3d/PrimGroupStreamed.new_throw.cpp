// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002df4d0..0x002e1610 (kind game, layer engine, confidence high), dominant class pure3d::PrimGroupStreamed
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fd7377f4 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd7377f4 {} using namespace fn_fd7377f4;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fd7377f4 {
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
class VertexList_2e01d0 {
public:
    VertexList_2e01d0(int a, int b, int c) throw();
    virtual void AddRef();
    virtual void Release();
};
namespace pure3d {
class PrimGroupBase {
public:
    virtual void b0_00038290();
    char pad04[0x3c];
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[4];
    int f58;
    VertexList_2e01d0* f5c;
    PrimGroupBase() throw();
};
}
namespace pure3d {
class PrimGroupStreamed : public PrimGroupBase {
public:
    PrimGroupStreamed(int a, int b, int c);
    virtual void s0_000382a0();
};
}


// 0x002e01d0 FUN_002e01d0 (121 B): equivalent/0x002e01d0.cpp
// sym: ??0PrimGroupStreamed@pure3d@fn_fd7377f4@@QAE@HHH@Z @1db7a5d79aac @w2c657f2fd52c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002e01d0 @ 0x002e01d0
// equiv-map: ??0Sub@@QAE@HHH@Z = 0x002c86d0
// equiv-map: ??0PrimGroupBase@pure3d@@QAE@XZ = 0x002a5060
namespace pure3d {
PrimGroupStreamed::PrimGroupStreamed(int a, int b, int c) : PrimGroupBase() {
    f40 = 0;
    f44 = 0;
    f48 = a;
    f4c = b;
    f50 = -1;
    f5c = 0;
    void* mem = FUN_0008d690(0x5c);
    VertexList_2e01d0* sub = 0;
    if (mem)
        sub = new (mem) VertexList_2e01d0(f48, b, c);
    f5c = sub;
    sub->AddRef();
    f58 = 0;
}
}

} // namespace fn_fd7377f4
