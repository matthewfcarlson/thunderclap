#include "decls/data/game/global.h"
// data: gManager_1ebd00 = DAT_004e36d8

class Temp_1ebd00 {
  public:
    void Init();
    void Add(const char*);
    void Finish();
};
class Manager_1ebd00 {
  public:
    void Run(char*, int, const char*, float);
};
class Owner_1ebd00 {
  public:
    void Go(const char*, const char*);
};
void Owner_1ebd00::Go(const char* a, const char* b) {
    if (!a || !*a)
        return;
    if (!b || !*b)
        return;
    char storage[0x48];
    Temp_1ebd00* t = (Temp_1ebd00*)storage;
    t->Init();
    t->Add("Objects");
    t->Add("FE");
    t->Add(a);
    if (*(char*)((char*)(*(Manager_1ebd00**)&DAT_004e36d8) + 8))
        ((Manager_1ebd00*)*(void**)(*(Manager_1ebd00**)&DAT_004e36d8))->Run((char*)t, 0, b, 100.0f);
    t->Finish();
}