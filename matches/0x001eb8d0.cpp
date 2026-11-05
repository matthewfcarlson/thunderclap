#include "compat/ptr.h"
#include "gen/owners.h"
class Temp_1eb8d0 {
  public:
    char pad[0x48];
    void Add(const char*);
};
class Manager_1eb8d0 {
  public:
};
class Root_1eb8d0 {
  public:
    void Run(Temp_1eb8d0*, int, int, float);
};
class Owner_1eb8d0 {
  public:
    Root_1eb8d0* root;
    Manager_1eb8d0* manager;
    unsigned char flag;
    void Target(hulk_intptr);
};
extern void __cdecl FUN_001eb440(void*, Temp_1eb8d0*);
void Owner_1eb8d0::Target(hulk_intptr arg) {
    Temp_1eb8d0 t;
    if (flag) {
        ((owners::Obj_1ef320 *)&t)->FUN_001ef320();
        t.Add("Objects");
        t.Add("Mix");
        void* p = ((void *)((owners::C_86310 *)manager)->FUN_00086310());
        if (p)
            FUN_001eb440(p, &t);
        if (flag)
            root->Run(&t, 0, arg, 100.0f);
        ((owners::C_1ef350 *)&t)->FUN_001ef350();
    }
}