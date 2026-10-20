// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_2 @ 0x000cec00
#include "gen/global.h"

struct HUDOverlay_cec00 {
    int FUN_000cec00(int a, const char *b, const char *c);
};
struct Function_cec00 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Method3<HUDOverlay, int, const char *, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cec00 * object = (HUDOverlay_cec00 *)__p0; unsigned int * arguments = (unsigned int *)__p1; int * result = (int *)__p2;

    int value = (object->*(*(int (HUDOverlay_cec00::**)(int, const char *, const char *))&this->f_1c))(arguments[0], (const char *)arguments[1], (const char *)arguments[2]);
    if (result) *result = value;
}
