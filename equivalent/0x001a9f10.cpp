// STATUS: equivalent (tools/equiv.py level 3: 8576 inputs, branch coverage 22/22)
// FUN_001a9f10 @ 0x001a9f10
// FUN_001a9f10 @ 0x001a9f10
#include "decls/address.h"
struct Vec3_1a9f10 {
    float x, y, z;
};

struct RefObj_1a9f10 {
    virtual void AddRef();
    virtual void Release();
};

struct Table_1a9f10 {
    char pad[4];
};

struct Pool_1a9f10 {
    unsigned char FUN_0002bf80(const char* name, Vec3_1a9f10 pos, int zero0, const char* s1, const char* s2, int zero1, char* buf);
    RefObj_1a9f10* FUN_00024280(unsigned __int64 id);
};

struct World {
    char pad0[0x20];
    Pool_1a9f10* pool;
};

struct Slot_1a9f10 {
    char active;
    char flagB;
    char flagC;
    char pad3[9];
    RefObj_1a9f10* ref;
    char pad10[8];
};

extern unsigned int DAT_004d9968;

extern "C" void __fastcall __security_check_cookie(unsigned int);

const char* FUN_001a4cb0(Table_1a9f10* t, unsigned int idx);
const char* FUN_001a4e40(Table_1a9f10* t, unsigned int idx);
bool FUN_001a5110(Table_1a9f10* t, unsigned int idx);
bool FUN_001a4fd0(Table_1a9f10* t, unsigned int idx);
void FUN_00267760(char* buf, int size, const char* fmt, ...);

struct Obj_1a9f10 {
    char pad0[0x1c];
    Table_1a9f10* table;
    char pad20[0xc];
    Slot_1a9f10 slots[20];
    void FUN_001a54a0(Vec3_1a9f10* pos, float* radius);
    int FUN_001a5340(unsigned int idx);
    bool FUN_001a9b10(Slot_1a9f10* slot, const char* name, char* buf, bool a, bool b, int c, bool d);
    bool FUN_001a9f10();
};

union NameOrRadius {
    float radius;
    const char* name;
};

struct Frame_1a9f10 {
    char pad10[3];
    bool any;
    unsigned int idx;
    Obj_1a9f10* self;
    bool helmet;
    NameOrRadius u;
    bool isCustom;
    Vec3_1a9f10 pos;
    char buf[0x80];
    unsigned int cookie;
};

bool Obj_1a9f10::FUN_001a9f10()
{
    Frame_1a9f10 f;
    f.cookie = DAT_004d9968;
    char* buf = f.buf;
    buf[0] = 0;
    for (int z = 1; z < 0x80; z++)
        buf[z] = 0;

    f.any = false;
    f.idx = 0;
    f.self = this;
    FUN_001a54a0(&f.pos, &f.u.radius);

    // the helmet file name is compared before the first table lookup (the stubbed lookup remaps memory)
    f.helmet = false;
    {
        const char* file = *(const char* const*)((const char*)table + 0x4c);
        f.helmet = true;
        for (int k = 0; k < 21; k++) {
            if (file[k] != "1aa_01_vr_helmet.p3d"[k]) {
                f.helmet = false;
                break;
            }
        }
    }

    const char* name = FUN_001a4cb0(table, 0);
    Slot_1a9f10* slot = &slots[0];
    while (name != 0) {
        unsigned int i = f.idx;
        Table_1a9f10* t = f.self->table;
        f.u.name = FUN_001a4e40(t, i);
        if (f.u.name != 0) {
            f.isCustom = FUN_001a5110(t, i);
            if (f.isCustom) {
                slot->flagB = 0;
                slot->flagC = 1;
                const char* s = name;
                char* d = buf;
                do {
                    *d = *s;
                    d++;
                } while (*s++ != 0);
            } else {
                int n = 0;
                const char* hulk = "hulk";
                bool same = true;
                for (n = 0; n < 5; n++) {
                    if (name[n] != hulk[n]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    FUN_00267760(buf, 0x80, "hulk");
                    slot->flagB = 0;
                    slot->flagC = 0;
                } else {
                    FUN_00267760(buf, 0x80, "%s_nis_%d", name, i);
                    unsigned char ok = DAT_004dd700->pool->FUN_0002bf80(name, f.pos, 0, "none", "none", 0, buf);
                    slot->flagC = 0;
                    if (ok == 1) {
                        slot->flagB = ok;
                        slot->active = ok;
                        Pool_1a9f10* pool = DAT_004dd700->pool;
                        RefObj_1a9f10* obj = pool->FUN_00024280(FUN_002672f0(name, 0, 0));
                        if (obj)
                            obj->AddRef();
                        if (slot->ref)
                            slot->ref->Release();
                        slot->ref = obj;
                    }
                }
                i = f.idx;
            }
            Obj_1a9f10* o = f.self;
            if (o->FUN_001a9b10(slot, f.u.name, buf, FUN_001a4fd0(o->table, i), f.isCustom, o->FUN_001a5340(i), f.helmet))
                f.any = true;
        }
        f.idx = f.idx + 1;
        slot++;
        name = FUN_001a4cb0(f.self->table, f.idx);
    }
    __security_check_cookie(f.cookie);
    return f.any;
}
