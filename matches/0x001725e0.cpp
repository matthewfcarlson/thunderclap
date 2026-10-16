#include "gen/hulkfight.h"

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
    Entry_1725e0* get(int);
};
struct Root_1725e0 {
    char pad[0x20];
    Manager_1725e0* manager;
};
struct A_1725e0 {
    void* call();
};
struct B_1725e0 {
    void* call();
};
struct E_1725e0 {
    void call();
};
extern A_1725e0* aFn;
extern B_1725e0* bFn;
extern E_1725e0* eFn;
extern Root_1725e0* gRoot_1725e0;

void hulkfight::motion::TargetBreakAction::vfunc_4() {
    void* a = ((A_1725e0*)(*(void * *)&this->f_1c))->call();
    if (a) {
        Obj_1725e0* b = (Obj_1725e0*)a;
        b = (Obj_1725e0*)((B_1725e0*)a)->call();
        if (b) {
            int id = b->id;
            if (id) {
                Manager_1725e0* m = gRoot_1725e0->manager;
                int count = m->count;
                for (int i = 0; i < count; ++i) {
                    Entry_1725e0* e = m->get(i);
                    if (e->id == id) {
                        ((E_1725e0*)e)->call();
                        e->flag = 0;
                    }
                }
            }
        }
    }
}
