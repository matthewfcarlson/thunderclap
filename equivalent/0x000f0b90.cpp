// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 84/92, incomplete)
// FUN_000f0b90 @ 0x000f0b90
extern "C" int strcmp(const char *a, const char *b);

struct Res_f0b90 {
    virtual void v0();
    virtual void v1();
};

struct Obj_f0b90 {
    virtual ~Obj_f0b90();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7();
    virtual const char *v8();
    char pad[0x858 - 4];
    char name[1];           // 0x858
};

struct Pair_f0b90 {
    Res_f0b90 *res[2];
};

struct Mgr_f0b90 {
    char pad0[0xc];
    Obj_f0b90 *objs[0x40];                // 0xc
    char pad10c[0x20c - 0x10c];
    Obj_f0b90 *objs2[0x100];              // 0x20c
    char pad60c[0x160c - 0x60c];
    void *bufs[0x40];               // 0x160c
    char curName[0x175c - 0x170c];  // 0x170c
    Obj_f0b90 *cur;                       // 0x175c
    char pad1760[0x1854 - 0x1760];
    Res_f0b90 *rA[2];                     // 0x1854
    char nameA[2][0x100];           // 0x185c
    Res_f0b90 *rB[2];                     // 0x1a5c
    char nameB[2][0x100];           // 0x1a64
    Res_f0b90 *rC[2];                     // 0x1c64
    char padC[8];
    char nameC[2][0x100];           // 0x1c74
    void FUN_000f0b90(const char *name);
};

// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
extern void __cdecl thunk_FUN_00267090(void *p);

void Mgr_f0b90::FUN_000f0b90(const char *name)
{
    if (name == 0)
        return;
    for (int i = 0; i < 0x40; i++) {
        Obj_f0b90 *o = objs[i];
        if (o != 0 && strcmp(o->name, name) == 0) {
            if (strcmp(o->v8(), curName) == 0)
                curName[0] = 0;
            if (cur == objs[i])
                cur = 0;
            if (objs[i] != 0) {
                delete objs[i];
                objs[i] = 0;
            }
        }
    }
    for (int i = 0; i < 0x100; i++) {
        Obj_f0b90 *o = objs2[i];
        if (o != 0 && strcmp(o->name, name) == 0) {
            delete o;
            objs2[i] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (strcmp(nameA[i], name) == 0 && rA[i] != 0) {
            rA[i]->v1();
            rA[i] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (strcmp(nameB[i], name) == 0 && rB[i] != 0) {
            rB[i]->v1();
            rB[i] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (strcmp(nameC[i], name) == 0 && rC[i] != 0) {
            rC[i]->v1();
            rC[i] = 0;
        }
    }
    for (int i = 0; i < 0x40; i++) {
        if (bufs[i] != 0) {
            thunk_FUN_00267090(bufs[i]);
            bufs[i] = 0;
        }
    }
}
