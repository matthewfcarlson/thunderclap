// STATUS: equivalent (tools/equiv.py level 3: 2697 inputs, branch coverage 70/71, incomplete)
// pure3d::LightLoader::vfunc_5 @ 0x002c0cf0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "gen/pure3d.h"
#include "decls/address.h"

typedef unsigned __int64 u64_2c0cf0;
void *thunk_FUN_0008d690(unsigned int size);

struct Reader_2c0cf0 {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream_2c0cf0 {
    char pad0[0x284];
    Reader_2c0cf0 *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

struct NameField_2c0cf0 {
    void FUN_0027b040(const char *name);
};

class Light_2c0cf0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(unsigned int x, unsigned int y, unsigned int z);
    virtual void v8(unsigned int *vec);
    char pad04[4];
    NameField_2c0cf0 name;
    char pad09[0x12 - 9];
    char flag12;
    char pad13[0x28 - 0x13];
    char flag28;
    void FUN_002a07a0(unsigned int v);
    void FUN_002a0820(unsigned int v);
    void FUN_002a0840(unsigned int v);
    void FUN_002a0ba0(unsigned int *a, unsigned int *b);
    void FUN_002a08c0(unsigned int v);
    void FUN_002a08f0(unsigned int v);
};

class Light0 : public Light_2c0cf0 {
public:
    Light0 *FUN_002a1230();
};

class Light1 : public Light_2c0cf0 {
public:
    Light1 *FUN_002c3e10();
    void FUN_002c3f00(unsigned int a, unsigned int b, unsigned int c);
};

class Light2 : public Light_2c0cf0 {
public:
    Light2 *FUN_002a2e70();
    void FUN_002a2ef0(unsigned int a, unsigned int b, unsigned int c);
};

class Light3 : public Light_2c0cf0 {
public:
    Light3 *FUN_002c4020();
    void FUN_002c4130(unsigned int a, unsigned int b, unsigned int c);
    void FUN_002c41e0(unsigned int a, unsigned int b, unsigned int c);
    void FUN_002c4170(unsigned int v);
    void FUN_002c41a0(unsigned int a, unsigned int b, unsigned int c);
};

class Light4 : public Light_2c0cf0 {
public:
    Light4 *FUN_002c3c10();
    void FUN_002c3d00(unsigned int a, unsigned int b, unsigned int c);
    void FUN_002c3ce0(unsigned int v);
};


union Flag_2c0cf0 {
    unsigned char b;
    unsigned int w;
};

void pure3d::LightLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int unused) { Light_2c0cf0 ** out = (Light_2c0cf0 **)__p0; u64_2c0cf0 * id = (u64_2c0cf0 *)__p1; Stream_2c0cf0 * s = (Stream_2c0cf0 *)__p2;

    struct Frame {
        char pad00[3];
        char b13;                 // also holds the name length early on
        unsigned int i14;
        unsigned int a18;
        Flag_2c0cf0 f1c;
        unsigned int v20;
        unsigned int pos[3];
        unsigned int s30, s34, s38;
        unsigned int e3c[3];
        unsigned int dir[3];
        unsigned int t54, t58;
        unsigned int e5c[3];
        unsigned int type;
        unsigned int t6c, t70, t74, t78, t7c, t80, t84, t88, t8c;
        char name[0x100];
    } F;
    int shapeKind;
    int mode;
    Light_2c0cf0 *obj;
    Light_2c0cf0 *result;
    s->reader->FUN_002647e0(&F.b13, 1, 1, 1);
    unsigned int len = (unsigned char)F.b13;
    s->reader->FUN_002647e0(F.name, len, 1, 1);
    F.name[len] = 0;
    *id = FUN_002672f0(F.name, 0, 0);
    s->reader->FUN_002647e0(&F.type, 1, 4, 1);
    s->reader->FUN_002647e0(&F.type, 1, 4, 1);
    s->reader->FUN_002647e0(&F.a18, 1, 4, 1);
    s->reader->FUN_002647e0(&F.s34, 1, 4, 1);
    s->reader->FUN_002647e0(&F.s30, 1, 4, 1);
    s->reader->FUN_002647e0(&F.s38, 1, 4, 1);
    s->reader->FUN_002647e0(&F.v20, 1, 4, 1);
    F.f1c.b = (F.v20 != 0);
    F.dir[0] = 0;
    F.dir[1] = 0xbf800000;
    F.dir[2] = 0;
    F.pos[0] = 0;
    F.pos[1] = 0;
    F.pos[2] = 0;
    F.t6c = 0;
    F.t58 = 0;
    F.v20 = 0;
    F.t54 = 0;
    F.e5c[0] = 0;
    F.e5c[1] = 0;
    F.e5c[2] = 0;
    F.e3c[0] = 0;
    F.e3c[1] = 0;
    F.e3c[2] = 0;
    F.i14 = 0;
    F.b13 = 0;
    mode = 0;
    shapeKind = 0;
    while (s->FUN_002669f0()) {
        s->FUN_00266a30();
        switch (s->FUN_00266c30()) {
        case 0x13001:
            s->reader->FUN_002647e0(F.dir, 3, 4, 1);
            break;
        case 0x13002:
            s->reader->FUN_002647e0(F.pos, 3, 4, 1);
            break;
        case 0x13003:
            s->reader->FUN_002647e0(&F.t7c, 1, 4, 1);
            F.t58 = F.t7c;
            s->reader->FUN_002647e0(&F.t70, 1, 4, 1);
            F.t6c = F.t70;
            s->reader->FUN_002647e0(&F.t74, 1, 4, 1);
            F.t54 = F.t74;
            s->reader->FUN_002647e0(&F.t78, 1, 4, 1);
            F.v20 = F.t78;
            break;
        case 0x13004:
            s->reader->FUN_002647e0(&F.t8c, 1, 4, 1);
            F.b13 = 1;
            break;
        case 0x13006:
            s->reader->FUN_002647e0(&F.t80, 1, 4, 1);
            if (F.t80 == 1)
                shapeKind = 1;
            else if (F.t80 == 2)
                shapeKind = 2;
            else if (F.t80 == 3)
                shapeKind = 3;
            else
                shapeKind = 0;
            s->reader->FUN_002647e0(F.e5c, 3, 4, 1);
            s->reader->FUN_002647e0(F.e3c, 3, 4, 1);
            while (s->FUN_002669f0()) {
                s->FUN_00266a30();
                if (s->FUN_00266c30() == 0x13007) {
                    s->reader->FUN_002647e0(&F.t88, 1, 4, 1);
                    F.i14 = F.t88;
                }
                s->FUN_00266be0();
            }
            break;
        case 0x13008:
            s->reader->FUN_002647e0(&F.t84, 1, 4, 1);
            if (F.t84 == 1)
                mode = 1;
            else if (F.t84 == 2)
                mode = 2;
            else
                mode = 0;
            break;
        }
        s->FUN_00266be0();
    }
    result = 0;
    switch (F.type) {
    case 0: {
        void *mem = thunk_FUN_0008d690(0x58);
        obj = mem ? ((Light0 *)mem)->FUN_002a1230() : 0;
        obj->name.FUN_0027b040(F.name);
        obj->FUN_002a07a0(F.a18);
        obj->v8(F.pos);
        obj->FUN_002a0820(F.f1c.w);
        obj->FUN_002a0840(shapeKind);
        obj->FUN_002a0ba0(F.e5c, F.e3c);
        obj->FUN_002a08c0(F.i14);
        obj->FUN_002a08f0(mode);
        result = obj;
        break;
    }
    case 1: {
        void *mem = thunk_FUN_0008d690(0x68);
        Light1 *o = mem ? ((Light1 *)mem)->FUN_002c3e10() : 0;
        obj = o;
        obj->name.FUN_0027b040(F.name);
        obj->FUN_002a07a0(F.a18);
        obj->v7(F.pos[0], F.pos[1], F.pos[2]);
        obj->FUN_002a0820(F.f1c.w);
        o->FUN_002c3f00(F.s34, F.s30, F.s38);
        obj->FUN_002a0840(shapeKind);
        obj->FUN_002a0ba0(F.e5c, F.e3c);
        obj->flag12 = F.b13;
        obj->FUN_002a08c0(F.i14);
        obj->FUN_002a08f0(mode);
        result = obj;
        break;
    }
    case 2: {
        void *mem = thunk_FUN_0008d690(0x68);
        Light2 *o = mem ? ((Light2 *)mem)->FUN_002a2e70() : 0;
        obj = o;
        obj->name.FUN_0027b040(F.name);
        obj->FUN_002a07a0(F.a18);
        obj->v8(F.pos);
        o->FUN_002a2ef0(F.dir[0], F.dir[1], F.dir[2]);
        obj->FUN_002a0820(F.f1c.w);
        obj->FUN_002a0840(shapeKind);
        obj->FUN_002a0ba0(F.e5c, F.e3c);
        obj->flag12 = F.b13;
        obj->FUN_002a08c0(F.i14);
        obj->FUN_002a08f0(mode);
        result = obj;
        break;
    }
    case 3: {
        void *mem = thunk_FUN_0008d690(0x80);
        Light3 *o = mem ? ((Light3 *)mem)->FUN_002c4020() : 0;
        obj = o;
        obj->name.FUN_0027b040(F.name);
        obj->FUN_002a07a0(F.a18);
        o->FUN_002c4130(F.dir[0], F.dir[1], F.dir[2]);
        obj->v7(F.pos[0], F.pos[1], F.pos[2]);
        o->FUN_002c41e0(F.t58, F.t6c, F.t54);
        o->FUN_002c4170(F.v20);
        obj->FUN_002a0820(F.f1c.w);
        o->FUN_002c41a0(F.s34, F.s30, F.s38);
        obj->FUN_002a0840(shapeKind);
        obj->FUN_002a0ba0(F.e5c, F.e3c);
        obj->flag12 = F.b13;
        obj->FUN_002a08c0(F.i14);
        obj->FUN_002a08f0(mode);
        result = obj;
        break;
    }
    case 4: {
        void *mem = thunk_FUN_0008d690(0x68);
        Light4 *o = mem ? ((Light4 *)mem)->FUN_002c3c10() : 0;
        obj = o;
        obj->name.FUN_0027b040(F.name);
        obj->FUN_002a07a0(F.a18);
        obj->v7(F.pos[0], F.pos[1], F.pos[2]);
        obj->FUN_002a0820(F.f1c.w);
        o->FUN_002c3d00(F.s34, F.s30, F.s38);
        obj->FUN_002a0840(shapeKind);
        obj->FUN_002a0ba0(F.e5c, F.e3c);
        if (shapeKind != 0)
            o->FUN_002c3ce0(F.e3c[0]);
        obj->flag12 = F.b13;
        obj->FUN_002a08c0(F.i14);
        obj->FUN_002a08f0(mode);
        result = obj;
        break;
    }
    }
    if ((F.name[0] == 'p' && F.name[1] == 'r' && F.name[2] == 'o' && F.name[3] == 'p' && F.name[4] == '_') ||
        (F.name[7] == 'p' && F.name[8] == 'r' && F.name[9] == 'o' && F.name[10] == 'p' && F.name[11] == '_')) {
        result->flag28 = 1;
        *out = result;
        return;
    }
    result->flag28 = 0;
    *out = result;
}
