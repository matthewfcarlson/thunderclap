#include "gen/global.h"
extern int g_table_c5820[];

struct CFESoundManager_c5820 : ISoundManager {
    virtual void f2(int, int);
};
void CFESoundManager_c5820::f2(int a, int index) {
    vfunc_1((void *)(a), (void *)(g_table_c5820[index]));
}
