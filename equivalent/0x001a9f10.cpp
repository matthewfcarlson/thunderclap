// STATUS: equivalent (tools/equiv.py level 3: 171 inputs, branch coverage 22/22)
// FUN_001a9f10 @ 0x001a9f10
struct Vec3 {
    float x, y, z;
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

struct Table {
    char pad[4];
};

struct Pool {
    unsigned char FUN_0002bf80(const char* name, Vec3 pos, int zero0, const char* s1, const char* s2, int zero1, char* buf);
    RefObj* FUN_00024280(unsigned __int64 id);
};

struct Manager {
    char pad0[0x20];
    Pool* pool;
};

struct Slot {
    char active;
    char flagB;
    char flagC;
    char pad3[9];
    RefObj* ref;
    char pad10[8];
};

extern Manager* DAT_004dd700;
extern unsigned int DAT_004d9968;

extern "C" void __fastcall __security_check_cookie(unsigned int);

const char* FUN_001a4cb0(Table* t, unsigned int idx);
const char* FUN_001a4e40(Table* t, unsigned int idx);
bool FUN_001a5110(Table* t, unsigned int idx);
bool FUN_001a4fd0(Table* t, unsigned int idx);
void FUN_00267760(char* buf, int size, const char* fmt, ...);
unsigned __int64 FUN_002672f0(const char* s, int a, int b);

struct Obj {
    char pad0[0x1c];
    Table* table;
    char pad20[0xc];
    Slot slots[20];
    void FUN_001a54a0(Vec3* pos, float* radius);
    int FUN_001a5340(unsigned int idx);
    bool FUN_001a9b10(Slot* slot, const char* name, char* buf, bool a, bool b, int c, bool d);
    bool FUN_001a9f10();
};

union NameOrRadius {
    float radius;
    const char* name;
};

struct Frame {
    char pad10[3];
    bool any;
    unsigned int idx;
    Obj* self;
    bool helmet;
    NameOrRadius u;
    bool isCustom;
    Vec3 pos;
    char buf[0x80];
    unsigned int cookie;
};

bool Obj::FUN_001a9f10()
{
    Frame f;
    f.cookie = DAT_004d9968;
    char* buf = f.buf;
    buf[0] = 0;
    for (int z = 1; z < 0x80; z++)
        buf[z] = 0;

    f.any = false;
    f.idx = 0;
    f.self = this;
    FUN_001a54a0(&f.pos, &f.u.radius);

    const char* name = FUN_001a4cb0(table, 0);
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

    Slot* slot = &slots[0];
    while (name != 0) {
        unsigned int i = f.idx;
        Table* t = f.self->table;
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
                        Pool* pool = DAT_004dd700->pool;
                        RefObj* obj = pool->FUN_00024280(FUN_002672f0(name, 0, 0));
                        if (obj)
                            obj->AddRef();
                        if (slot->ref)
                            slot->ref->Release();
                        slot->ref = obj;
                    }
                }
                i = f.idx;
            }
            Obj* o = f.self;
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
