// STATUS: equivalent (tools/equiv.py level 3: 10398 inputs, branch coverage 15/16, incomplete)
// FUN_0008cbe0 @ 0x0008cbe0
// cl-flags: /GS
#include "decls/address.h"
struct Engine_8cbe0 {
    void FUN_001eb870();
    void FUN_001eb890();
};

struct Singleton_4dd6ec {
    Engine_8cbe0 *FUN_000862e0();
};


void *FUN_0008d690(unsigned int size);
int __cdecl FUN_00266da0(int mode);
void __cdecl FUN_0026b800(char *buf, int a, int b, int c, int d, int e, int f);
void __cdecl FUN_0008d330(void *p);

class SubObj_8cbe0 {
public:
    virtual void v0();
    virtual void Release();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(int a, int b, int c);
    virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21();
    virtual void *v22();
    virtual char v23();
};

class Source;
class Stage_8cbe0 {
public:
    virtual void v0();
    virtual void Release();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21();
};

class Slot_8cbe0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual int v22();
    virtual void *v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(SubObj_8cbe0 **out, char *buf, int a, int b, void *c, int d, int e);
};

struct Entry_8cbe0 {
    Slot_8cbe0 *slot;
    Stage_8cbe0 *stage;
    char pad[0xc8 - 8];
};

class Loader_8cbe0 {
public:
    void *FUN_0008cbe0(int index, int a, int b, int c, int d);

    char pad0[4];
    int param;
    Entry_8cbe0 *entries;
};

void *Loader_8cbe0::FUN_0008cbe0(int index, int a, int b, int c, int d)
{
    char buf[0x100];
    DAT_004dd6ec->FUN_000862e0()->FUN_001eb870();
    Slot_8cbe0 *slot = entries[index].slot;
    slot->v22();
    if (entries[index].stage) {
        entries[index].stage->v21();
        Stage_8cbe0 **slotStage = &entries[index].stage;
        Stage_8cbe0 *stage = *slotStage;
        if (stage) {
            stage->Release();
            *slotStage = 0;
        }
    }
    int prev = FUN_00266da0(1);
    int *state = (int *)FUN_0008d690(8);
    state[0] = 0;
    state[1] = 0;
    FUN_00266da0(prev);
    FUN_0026b800(buf, 1, d, 2, 0x2e, 0x100, 0);
    SubObj_8cbe0 *sub = 0;
    slot->v36(&sub, buf, 1, 3, state, param, 1);
    void *result = slot->v23();
    FUN_0008d330(state);
    if (sub) {
        if (!result) {
            result = sub->v22();
            if (!result && sub->v23()) {
                sub->v10(b, c, 1);
                result = sub->v22();
                if (!result) {
                    sub->v14();
                    result = sub->v22();
                }
            }
        }
        if (sub) {
            sub->Release();
            sub = 0;
        }
    }
    DAT_004dd6ec->FUN_000862e0()->FUN_001eb890();
    return result;
}
