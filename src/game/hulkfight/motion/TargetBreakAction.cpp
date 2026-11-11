// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001725e0..0x00172650 (kind game, layer game, confidence medium), dominant class hulkfight::motion::TargetBreakAction
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f4d9adfa {
#define TREE_TU_END }
namespace fn_f4d9adfa {} using namespace fn_f4d9adfa;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4d9adfa {
struct Obj_1725e0 {
    char pad[0x12c];
    int id;
};
struct Entry_1725e0 {
    char pad[0x328];
    int id;
    char flag;
};
struct Manager_1725e0 {
    char pad[0xc];
    int count;
    Entry_1725e0* get_00024190(int);
};
struct Root_1725e0 {
    char pad[0x20];
    Manager_1725e0* manager;
};
struct A_1725e0 {
    void* call_000592a0();
};
struct B_1725e0 {
    void* call_00059a30();
};
struct E_1725e0 {
    void call_000393c0();
};
extern A_1725e0* aFn;
extern B_1725e0* bFn;
extern E_1725e0* eFn;
extern Root_1725e0* hulk_at_004dd700;

} // namespace fn_f4d9adfa

// 0x001725e0 hulkfight::motion::TargetBreakAction::vfunc_4 (111 B): matches/0x001725e0.cpp
// sym: ?vfunc_4@TargetBreakAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::TargetBreakAction::vfunc_4() {
    void* a = ((A_1725e0*)(*(void * *)&this->f_1c))->call_000592a0();
    if (a) {
        Obj_1725e0* b = (Obj_1725e0*)a;
        b = (Obj_1725e0*)((B_1725e0*)a)->call_00059a30();
        if (b) {
            int id = b->id;
            if (id) {
                Manager_1725e0* m = hulk_at_004dd700->manager;
                int count = m->count;
                for (int i = 0; i < count; ++i) {
                    Entry_1725e0* e = m->get_00024190(i);
                    if (e->id == id) {
                        ((E_1725e0*)e)->call_000393c0();
                        e->flag = 0;
                    }
                }
            }
        }
    }
}

