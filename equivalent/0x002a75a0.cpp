// STATUS: equivalent (tools/equiv.py level 3: 34 inputs, branch coverage 25/30, incomplete)
// FUN_002a75a0 @ 0x002a75a0
#include "compat/ptr.h"
class Owned_2a75a0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct SourceEntry_2a75a0 {
    Owned_2a75a0 *item;
    int pad[3];
};

struct Source_2a75a0 {
    char pad00[0x48];
    SourceEntry_2a75a0 *begin;
    SourceEntry_2a75a0 *end;
    char pad50[8];
    char flag;
    char pad59[3];
    int valueA;
    int valueB;
};

void *__cdecl FUN_0008d6d0(hulk_uintptr size);
void __cdecl FUN_0008d340(void *p);

class Holder_2a75a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void vfunc_14(int a, int b);
    char pad04[0x24 - 4];
    int notFlag;
    char pad28[0x40 - 0x28];
    char flag;
    char pad41[3];
    int valueA;
    int valueB;
    char pad4c[4];
    Owned_2a75a0 **begin;
    Owned_2a75a0 **end;
    void FUN_002a75a0(const Source_2a75a0 *src);
};

void Holder_2a75a0::FUN_002a75a0(const Source_2a75a0 *src)
{
    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++) {
        Owned_2a75a0 **slot = &begin[i];
        Owned_2a75a0 *o = *slot;
        if (o) {
            o->vfunc_1();
            *slot = 0;
        }
    }

    if ((unsigned int)(src->end - src->begin) != (unsigned int)(end - begin)) {
        if (begin)
            FUN_0008d340(begin);
        begin = 0;
        end = 0;
        unsigned int n = (unsigned int)(src->end - src->begin);
        if (n == 0) {
            begin = 0;
            end = 0;
        } else {
            Owned_2a75a0 **mem = (Owned_2a75a0 **)FUN_0008d6d0(n * 4);
            begin = mem;
            if (mem == 0) {
                begin = 0;
                end = 0;
            } else {
                end = mem + n;
                for (; n != 0; n--) {
                    if (mem)
                        *mem = 0;
                    mem++;
                }
            }
        }
    }

    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++) {
        Owned_2a75a0 *o = src->begin[i].item;
        Owned_2a75a0 **slot = &begin[i];
        if (o)
            o->vfunc_0();
        if (*slot)
            (*slot)->vfunc_1();
        *slot = o;
    }

    flag = src->flag;
    notFlag = (src->flag == 0);
    valueA = src->valueA;
    valueB = src->valueB;
    vfunc_14(0, src->valueA);
}
