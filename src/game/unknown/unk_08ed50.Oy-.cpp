// cl-flags: /Oy-
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008ed50..0x0008ff70 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7b5f211 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7b5f211 {} using namespace fn_f7b5f211;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f7b5f211 {
extern "C" void FUN_0008ed60();
extern "C" void FUN_0008d660();
extern "C" void FUN_0026f070();
extern "C" void FUN_0026eea0(int, int, int, int);
void thunk_FUN_002709b0(int, int, int, int);
void thunk_FUN_00270f10(const char*, void*);
extern "C" void FUN_00265b70(int);
extern "C" void FUN_0008fca0();
extern "C" void* FUN_0008d690(int);
void FUN_00333b80();
extern "C" void FUN_00268490();
extern "C" void FUN_00265c40();
extern "C" bool __cdecl thunk_FUN_00270f90(const char*);
void thunk_FUN_00271070();
extern "C" void FUN_0026f000();
extern "C" void FUN_0026eeb0();
extern "C" void FUN_00266d70();
extern "C" void FUN_0026dab0();
extern "C" void FUN_00267a90();
} // namespace fn_f7b5f211
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f7b5f211 {
class FUN_00087e80 {
  public:
    FUN_00087e80();
    virtual void Vfn(int);
    int fields[19];
    unsigned char flag;
};


// 0x0008ee30 FUN_0008ee30 (194 B): matches/0x0008ee30.cpp
// sym: ?FUN_0008ee30@fn_f7b5f211@@YAHXZ
int FUN_0008ee30() {
    (*(int*)&DAT_004dd834) += 0x15b;
    FUN_0008ed60();
    (*(int*)&DAT_004dd830) = 0x2ad2b093;
    FUN_0008d660();
    FUN_0026f070();
    FUN_0026eea0(2, 0x2148, 0, 0);
    thunk_FUN_002709b0(0x32, 0x20, 0x8000, 0);
    thunk_FUN_00270f10(0, 0);
    FUN_00265b70(0);
    FUN_0008fca0();
    FUN_00087e80* esi;
    void* p = FUN_0008d690((int)sizeof(FUN_00087e80));
    if (p)
        esi = new (p) FUN_00087e80;
    else
        esi = 0;
    ((owners::Obj_88530 *)esi)->FUN_00088530();
    if (esi)
        esi->Vfn(1);
    FUN_00333b80();
    FUN_00268490();
    FUN_00265c40();
    thunk_FUN_00270f90((const char*)0);
    thunk_FUN_00271070();
    FUN_0026f000();
    FUN_0026eeb0();
    FUN_00266d70();
    FUN_0026dab0();
    FUN_00267a90();
    return 0;
}

} // namespace fn_f7b5f211
