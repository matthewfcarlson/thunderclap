// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0035a640..0x0035a7b0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#define TREE_TU_BEGIN namespace fn_f0fa2abb {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0fa2abb {} using namespace fn_f0fa2abb;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f0fa2abb {
class Item {
  public:
    virtual void A();
    virtual void B();
    virtual void Set(int);
    virtual int Get();
};
struct Item_35a720 {
    virtual void Run();
};
struct Obj_35a740 {
    virtual void f0();
    virtual void f1();
};

// 0x0035a640 thunk_FUN_0035a720 (5 B): not yet verified
// 0x0035a650 thunk_FUN_0035a740 (5 B): not yet verified

// 0x0035a660 FUN_0035a660 (60 B): matches/0x0035a660.cpp
// sym: ?FUN_0035a660@fn_f0fa2abb@@YAXXZ
// data: gCount = DAT_004dbf6c, gReady = DAT_0056f020, gValues = DAT_0056f000
void FUN_0035a660() {
    DAT_004dbf6c = 0x45;
    for (int i = 0; i < 8; ++i)
        ((int*)&DAT_0056f000)[i] = 0;
    (*(unsigned char*)&DAT_0056f020) = 1;
}


// 0x0035a6c0 FUN_0035a6c0 (86 B): matches/0x0035a6c0.cpp
// sym: _FUN_0035a6c0
// data: count = DAT_0056f024, current = DAT_004dbf6c, items = DAT_0056f000
extern "C" void FUN_0035a6c0(int v) {
    DAT_004dbf6c = v;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (*(int*)&DAT_0056f024); j++) {
            if (((Item**)&DAT_0056f000)[j]->Get() == i)
                ((Item**)&DAT_0056f000)[j]->Set(DAT_004dbf6c);
        }
    }
}


// 0x0035a720 FUN_0035a720 (27 B): matches/0x0035a720.cpp
// sym: ?Target@fn_f0fa2abb@@YAXPAUItem_35a720@1@@Z
// data: gCount_35a720 = DAT_0056f024, gItems_35a720 = DAT_0056f000
void __cdecl Target(Item_35a720* p) {
    ((Item_35a720**)&DAT_0056f000)[(*(int*)&DAT_0056f024)] = p;
    p->Run();
    ++(*(int*)&DAT_0056f024);
}


// 0x0035a740 FUN_0035a740 (97 B): matches/0x0035a740.cpp
// sym: ?RemoveObj@fn_f0fa2abb@@YAXPAUObj_35a740@1@@Z
// data: gCount_35a740 = DAT_0056f024, gList_35a740 = DAT_0056f000
void RemoveObj(Obj_35a740* o) {
    int i = 0;
    if ((*(int*)&DAT_0056f024) > 0) {
        do {
            if (((Obj_35a740**)&DAT_0056f000)[i] == o) {
                ((Obj_35a740**)&DAT_0056f000)[i]->f1();
                int last = (*(int*)&DAT_0056f024) - 1;
                ((Obj_35a740**)&DAT_0056f000)[i] = 0;
                (*(int*)&DAT_0056f024) = last;
                if (i != last) {
                    ((Obj_35a740**)&DAT_0056f000)[i] = ((Obj_35a740**)&DAT_0056f000)[last];
                    ((Obj_35a740**)&DAT_0056f000)[last] = 0;
                }
                return;
            }
            i++;
        } while (i < (*(int*)&DAT_0056f024));
    }
}

} // namespace fn_f0fa2abb
