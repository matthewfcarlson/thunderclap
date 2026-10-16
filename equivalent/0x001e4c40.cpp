// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 32/32)
// FUN_001e4c40 @ 0x001e4c40
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Vec3_1e4c40 {
    float x, y, z;
};

struct Mat4_1e4c40 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(Vec3_1e4c40 *pos);
};

class CSPHulkProp;

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Prop_1e4c40 {
    char pad[4];
};

struct Inventory_1e4c40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Prop_1e4c40 *v3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned __int64 key);
};

struct Counter_1e4c40 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};

struct Stats_1e4c40 {
    char pad0[0x80];
    Counter_1e4c40 counter;
};

struct Holder44_1e4c40 { Inventory_1e4c40 *FUN_00203d70(); };
struct Holder28_1e4c40 {
    Stats_1e4c40 *FUN_00086310();
    Holder44_1e4c40 *FUN_000862a0();
};

struct World {
    char pad0[0x54];
    Holder28_1e4c40 *holder;
};

struct Node {
    char pad0[0x144];
    char b144;
    char pad145[0x150 - 0x145];
    int f150;
    char pad154[0x194 - 0x154];
    char b194;
    char pad195[0x1c4 - 0x195];
    float f1c4;
    void FUN_001d86d0(Vec3_1e4c40 *dir, Vec3_1e4c40 *pos);
};

struct Factory_1e4c40 {
    Node *FUN_001e4760(Prop_1e4c40 *prop, char *name, int a, Mat4_1e4c40 *m, int b, int c, int d);
    Node *FUN_001e4c40(const char *key, Vec3_1e4c40 *pos, int type, char *name, Vec3_1e4c40 *dir, int c);
};

extern int DAT_004e274c;
extern float DAT_004c617c;
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern float DAT_004c6180;

int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
extern "C" int __cdecl sprintf(char *, const char *, ...);

Node *Factory_1e4c40::FUN_001e4c40(const char *key, Vec3_1e4c40 *pos, int type, char *name, Vec3_1e4c40 *dir, int c)
{
    struct Frame {
        char caster[4];
        Factory_1e4c40 *self;
        Mat4_1e4c40 m;
        char buf[0x80];
    } f;
    unsigned int cookie = DAT_004d9968;
    f.self = this;

    int a = DAT_004dd700->holder->FUN_00086310()->counter.FUN_00088fa0();
    int v = DAT_004dd700->holder->FUN_00086310()->counter.FUN_00088fb0();
    if (a == 0 && (v == 1 || v == 10)) {
        if (type == 1 || type == 2 || type == 3 || type == 4) {
            __security_check_cookie(cookie);
            return 0;
        }
    }

    f.m.FUN_0022b980();
    f.m.FUN_0022be40(pos);
    Inventory_1e4c40 *inv = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    unsigned __int64 id = FUN_002672f0(key, 0, 0);
    Prop_1e4c40 *prop = inv->v3(new (f.caster) content::LoadInventory::DynamicCaster<CSPHulkProp>, id);
    if (prop == 0) {
        FUN_000964a0(f.buf, 0x80, "%s_%s", key, key);
        id = FUN_002672f0(f.buf, 0, 0);
        prop = inv->v3(new (f.caster) content::LoadInventory::DynamicCaster<CSPHulkProp>, id);
    }

    Node *node = 0;
    if (prop != 0) {
        char *n = name;
        if (n == 0) {
            n = f.buf;
            sprintf(f.buf, "collectable%d", DAT_004e274c++);
        }
        node = f.self->FUN_001e4760(prop, n, 0, &f.m, 0, c, 0);
        if (node != 0) {
            node->f150 = type;
            node->b144 = 1;
            node->b194 = 1;
            if (dir != 0)
                node->FUN_001d86d0(dir, pos);
            if (type == 8 || type == 7 || type == 0xc || type == 0xd)
                node->f1c4 = DAT_004c6180;
            else
                node->f1c4 = DAT_004c617c;
        }
    }
    __security_check_cookie(cookie);
    return node;
}
