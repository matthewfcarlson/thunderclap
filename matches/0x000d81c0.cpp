#include "gen/owners.h"
class Chain_d81c0 {
  public:
    void B(int);
    int C(int, int);
    void D(int);
};
class Manager_d81c0 {
  public:
    Chain_d81c0* Get();
};
class Obj_d81c0 {
  public:
    char pad[0x150];
    Manager_d81c0* m;
};
int __fastcall target(Obj_d81c0* self, void*, int x, int y) {
    ((Chain_d81c0 *)((owners::Obj_89a50 *)(self->m->Get()))->FUN_00089a50())->B(x);
    int r = self->m->Get()->C(x, y);
    ((Chain_d81c0 *)((owners::Obj_89a50 *)(self->m->Get()))->FUN_00089a50())->D(x);
    return r;
}