#include "decls/data/game/global.h"
// data: key = DAT_004080a8

class Mgr_b7760 {
  public:
    char Check(int);
};
class Obj_b7760 {
    char pad[0x4c];

  public:
    Mgr_b7760* mgr;
    void Run();
};
struct Button_b7760 {
    char pad[0x141];
    char flag;
};
extern "C" void* __cdecl Find(const char*);
extern "C" Button_b7760* __cdecl Convert(void*, int, void*, void*, int);
extern int type1_b7760, type2;
void Obj_b7760::Run() {
    Button_b7760* b = Convert(Find(DAT_004080a8), 0, &type1_b7760, &type2, 0);
    if (b) {
        int count = 0;
        for (int i = 0x266; i <= 0x2c9; ++i)
            if (!mgr->Check(i))
                ++count;
        b->flag = count > 0;
    }
}