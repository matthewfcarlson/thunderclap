// STATUS: equivalent (tools/equiv.py level 3: 1073 inputs, branch coverage 38/38)
// FUN_0007d700 @ 0x0007d700
unsigned __int64 __cdecl FUN_0027b020(const char* s) throw();
void* __cdecl FUN_00263ea0(unsigned int size) throw();

struct Vec3 {
    float x, y, z;
};

struct Cell {
    Vec3 a;
    Vec3 b;
    int f18;
    int f1c;
    char pad20[8];
    int count;
    char pad2c[0x48 - 0x2c];
};

struct Entry {
    unsigned __int64 hash;
    int f08;
    int f0c;
};

struct Flags {
    bool FUN_00092940(int id);
};

struct Opt {
    Flags* FUN_00086340();
};

struct Globals {
    char pad00[0x54];
    Opt* opt;
};

struct Sim {
    int FUN_00011330(int n);
    float FUN_000787e0(unsigned __int64 id);
};

struct Wing {
    char pad00[0xc];
    struct Node* node;
};

struct Node {
    void FUN_001dc2d0(int id, int variant);
    void FUN_001dd890(int id, int flag);
};

struct Holder {
    char pad00[0xc];
    Node* node;
};

class Vehicle {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0xc8 - 4];
    Vehicle* FUN_00083c30(const char* name, int id, int rowField, int a4, int f18, Vec3 a, Vec3 b, float speed, int idx);
    void FUN_00083d50(float v);
    void FUN_00083d60(float v);
    void FUN_00083d70(float v);
};

extern Globals* DAT_004dd700;
extern unsigned DAT_004dd060;
extern unsigned __int64 DAT_004dd058;
extern unsigned __int64 DAT_004dd050;
extern float DAT_0049b888;
extern float DAT_0049b88c;
extern float DAT_0049b890;

void __cdecl FUN_00224d70(float angle, Vec3* v);
Sim* __cdecl FUN_000964d0();

union VariantOrSpeed {
    int variant;
    float speed;
};

class Spawner {
public:
    char pad0000[0x1904];
    Cell cells[1];
    char pad194c[0x3650 - 0x1904 - sizeof(Cell)];
    Entry entries[1];
    char pad3660[0x3718 - 0x3650 - sizeof(Entry)];
    int counts[1];
    char pad371c[0x3740 - 0x371c];
    int count;
    char pad3744[0x37a4 - 0x3744];
    unsigned int id37a4;
    unsigned int id37a8;
    char pad37ac[0x382c - 0x37ac];
    Holder* holder;
    int FUN_000798a0(unsigned __int64 id);
    int FUN_000796e0(Entry* entry, const char* name, Cell* cell, Vec3* dir, int a, int b, int c);
    int FUN_0007b820(Vehicle* v);
    void FUN_0007d700(const char* name, int idx, int row, int col);
};

void Spawner::FUN_0007d700(const char* name, int idx, int row, int col)
{
    if (idx < 0 || idx >= count)
        return;
    if (FUN_000798a0(FUN_0027b020(name)) != 0)
        return;
    Cell* cell = (Cell*)((char*)this + (row * 14 + col) * 0x48 + 0x1904);
    Entry* entry = (Entry*)((char*)this + 0x3650 + idx * 16);
    Vec3 d;
    d.x = cell->b.x - cell->a.x;
    d.y = cell->b.y - cell->a.y;
    d.z = cell->b.z - cell->a.z;
    FUN_00224d70(1.5707964f, &d);
    Sim* sim = FUN_000964d0();
    VariantOrSpeed slot;
    slot.variant = sim->FUN_00011330(entry->f08 - 1);
    Node* node = holder->node;
    Flags* flags = DAT_004dd700->opt->FUN_00086340();
    if (flags->FUN_00092940(0x26)) {
        if ((DAT_004dd060 & 1) == 0) {
            DAT_004dd060 |= 1;
            DAT_004dd058 = FUN_0027b020("bus1_bus1");
        }
        if (count > 0) {
            int i = 0;
            do {
                Entry* e = (Entry*)((char*)this + 0x3650 + i * 16);
                if (e->hash == DAT_004dd058) {
                    entry = e;
                    slot.variant = 0;
                    break;
                }
                i++;
            } while (i < count);
        }
    } else if (flags->FUN_00092940(0x16)) {
        if ((DAT_004dd060 & 2) == 0) {
            DAT_004dd060 |= 2;
            DAT_004dd050 = FUN_0027b020("carPT_carPT");
        }
        if (count > 0) {
            int i = 0;
            do {
                Entry* e = (Entry*)((char*)this + 0x3650 + i * 16);
                if (e->hash == DAT_004dd050) {
                    entry = e;
                    slot.variant = 1;
                    break;
                }
                i++;
            } while (i < count);
        }
    }
    int id = FUN_000796e0(entry, name, cell, &d, 0, 0, 0);
    if (id == -1)
        return;
    node->FUN_001dc2d0(id, slot.variant);
    node->FUN_001dd890(id, 1);
    slot.speed = sim->FUN_000787e0((unsigned __int64)id37a8 << 32 | id37a4);
    if (flags->FUN_00092940(0x25))
        slot.speed = slot.speed + slot.speed;
    Vehicle* v;
    void* mem = FUN_00263ea0(0xc8);
    if (mem != 0) {
        Cell* rowCell = (Cell*)((char*)this + row * 0x3f0 + 0x1904);
        v = ((Vehicle*)mem)->FUN_00083c30(name, id, rowCell->f1c, col, cell->f18, cell->a, cell->b, slot.speed, idx);
    } else {
        v = 0;
    }
    v->v0();
    if (FUN_0007b820(v) != -1) {
        v->FUN_00083d50(DAT_0049b888);
        v->FUN_00083d60(DAT_0049b88c);
        v->FUN_00083d70(DAT_0049b890);
        counts[idx]++;
        cell->count++;
    }
    v->v1();
}
