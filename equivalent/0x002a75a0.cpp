// STATUS: equivalent (tools/equiv.py level 3: 34 inputs, branch coverage 25/30, incomplete)
// FUN_002a75a0 @ 0x002a75a0
class Owned {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct SourceEntry {
    Owned *item;
    int pad[3];
};

struct Source {
    char pad00[0x48];
    SourceEntry *begin;
    SourceEntry *end;
    char pad50[8];
    char flag;
    char pad59[3];
    int valueA;
    int valueB;
};

void *__cdecl FUN_0008d6d0(unsigned int size);
void __cdecl FUN_0008d340(void *p);

class Holder {
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
    Owned **begin;
    Owned **end;
    void FUN_002a75a0(const Source *src);
};

void Holder::FUN_002a75a0(const Source *src)
{
    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++) {
        Owned **slot = &begin[i];
        Owned *o = *slot;
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
            Owned **mem = (Owned **)FUN_0008d6d0(n * 4);
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
        Owned *o = src->begin[i].item;
        Owned **slot = &begin[i];
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
