#include "compat/ptr.h"
extern "C" void __cdecl FUN_0014c550();
extern "C" char DAT_00414838[];
extern "C" void* FUN_0008d690(unsigned int);
extern "C" void FUN_002347b0(void*, void**, int);
extern int g_count_155500;
extern void* g_data_155500;
class Param {
  public:
    int a[4];
    int val;
};
class Hit_155500 : public Param {
  public:
    void Init(const char*);
};
void FUN_00155500() {
    void* temp;
    if (!g_count_155500) {
        Hit_155500* p = (Hit_155500*)FUN_0008d690(0x18);
        if (p) {
            p->Init("hasHitPushback");
            *(hulk_intptr*)p = ((hulk_intptr)DAT_00414838);
            *(hulk_intptr*)((char*)p + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_0014c550);
            temp = p;
        } else
            temp = 0;
        FUN_002347b0(&g_data_155500, &temp, 1);
    }
    ++g_count_155500;
}