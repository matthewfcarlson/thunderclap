#include "decls/data/game/global.h"
// data: gManager_1ebd00 = DAT_004e36d8
#include "gen/owners.h"

class Temp_1ebd00 {
  public:
    void Add(const char*);
};
class Manager_1ebd00 {
  public:
    void Run(char*, int, const char*, float);
};
void owners::Owner_1ebd00::FUN_001ebd00(const char* a, const char* b) {
    if (!a || !*a)
        return;
    if (!b || !*b)
        return;
    char storage[0x48];
    Temp_1ebd00* t = (Temp_1ebd00*)storage;
    ((owners::Obj_1ef320 *)t)->FUN_001ef320();
    t->Add("Objects");
    t->Add("FE");
    t->Add(a);
    if (*(char*)((char*)(*(Manager_1ebd00**)&DAT_004e36d8) + 8))
        ((Manager_1ebd00*)*(void**)(*(Manager_1ebd00**)&DAT_004e36d8))->Run((char*)t, 0, b, 100.0f);
    ((owners::C_1ef350 *)t)->FUN_001ef350();
}