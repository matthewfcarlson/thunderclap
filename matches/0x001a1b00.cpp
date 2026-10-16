#include "decls/data/game/hulkfight/scenario.h"

extern "C" char DAT_0041c3ac[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void FUN_002347b0(void*, void**, int);
extern "C" int g_count_1a1b00;
extern "C" void* g_slot_1a1b00;
class Base_1a1b00 {
  public:
    virtual void V0();
};
class ParamScript : public Base_1a1b00 {
  public:
    void Init(const char*);
    char pad[8];
    void* mFn;
};
void FUN_001a1b00() {
    void* tmp;
    if (g_count_1a1b00 == 0) {
        ParamScript* p = (ParamScript*)FUN_0008d690(0x18);
        if (p) {
            p->Init((const char*)((int)((char*)&DAT_0041c420)));
            *(unsigned int*)p = ((int)DAT_0041c3ac);
            *(unsigned int*)((char*)p + 0x10) = 0x1a1350;
            tmp = p;
        } else
            tmp = 0;
        FUN_002347b0(&g_slot_1a1b00, &tmp, 1);
    }
    ++g_count_1a1b00;
}