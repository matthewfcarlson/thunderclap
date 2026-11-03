#include "gen/owners.h"
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Obj_203a10 {
  public:
    bool A(int);
    bool B(int);
};
class Manager_203a10 {
  public:
};
class Root_203a10 {
  public:
    char pad[0x54];
    Manager_203a10* mgr;
};
extern Root_203a10* gRoot_203a10;
void owners::C_203a10::FUN_00203a10() {
    strncpy(name, "hulk", 0x20);
    Obj_203a10* o = ((Obj_203a10 *)((owners::A_86340 *)(gRoot_203a10->mgr))->FUN_00086340());
    if (o != 0) {
        int i = 0;
        while (o->A(i) || !o->B(i)) {
            ++i;
            if (i > 12)
                return;
        }
        if (i != -1)
            Apply(i);
    }
}
