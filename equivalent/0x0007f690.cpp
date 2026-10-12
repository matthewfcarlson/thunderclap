// STATUS: equivalent (tools/equiv.py level 3: 39 inputs, branch coverage 25/26, incomplete)
// FUN_0007f690 @ 0x0007f690
extern float DAT_0049b8a0;
extern float DAT_004218c0;
extern float DAT_00421898;

struct V3 {
    float x, y, z;
};

struct Rng {
    unsigned int s0;
    unsigned int s1;
};
Rng *FUN_000964d0();

struct Path {
    char pad0[0x14];
    int count;
    V3 *FUN_00106160(int index);
};

struct Library {
    Path *FUN_00106210(int id);
};

struct Manager {
    char pad0[0x18];
    Library *library;
};

struct Handle {
    void FUN_001c5080(float a, float b);
};

struct Part {
    virtual void AddRef();
    virtual void Release();
    char pad4[0x4];
    int key0;
    int key1;
    char pad10[0x54];
    V3 pos;
    char pad70[0x7c];
    Handle *handle;
    void FUN_00080ea0(V3 *a, V3 *b);
    void FUN_00080ef0(int v);
    void FUN_00080f00(int v);
    void FUN_00080f20(int v);
    void FUN_00080f30(int v);
    void FUN_00080e30(V3 *a);
    void FUN_00081b20(int v);
};

struct Slot16 {
    unsigned int limit;
    char pad4[12];
};

class Spawner {
public:
    char pad0[0x34b0];
    Slot16 slots[9];
    char pad3540[8];
    unsigned int slotCount;
    Part *parts[20];
    int partCount;
    char pad35a0[0x28c];
    Manager *mgr;
    void FUN_00078ee0(V3 *a, V3 *b);
    Part *FUN_0007f310(int a, int b, int c, int d);
    void FUN_0007f690(int a1, int a2, int a3, int a4);
};

void Spawner::FUN_0007f690(int a1, int a2, int a3, int a4)
{
    Path *path = mgr->library->FUN_00106210(a2);
    int i0;
    int i1;
    if (a4 == 0) {
        i0 = a3;
        i1 = (a3 + 1) % path->count;
    } else {
        i1 = a3;
        i0 = (a3 + 1) % path->count;
    }
    V3 a = *path->FUN_00106160(i0);
    V3 b = *path->FUN_00106160(i1);
    FUN_00078ee0(&a, &b);
    for (int i = partCount - 1; i >= 0; i--) {
        V3 p = parts[i]->pos;
        float dx = p.x - a.x;
        float dy = p.y - a.y;
        float dz = p.z - a.z;
        if (dz * dz + dy * dy + dx * dx < DAT_0049b8a0)
            return;
    }
    unsigned int n1 = slotCount;
    Rng *r = FUN_000964d0();
    r->s0 = (r->s0 & 0xffff) * 0x9069 + (r->s0 >> 16);
    r->s1 = (r->s1 & 0xffff) * 0x4650 + (r->s1 >> 16);
    unsigned int v1 = (r->s0 << 16) + (r->s1 & 0xffff);
    unsigned int pick = v1 % n1;
    unsigned int n2 = slots[pick].limit;
    r = FUN_000964d0();
    r->s0 = (r->s0 & 0xffff) * 0x9069 + (r->s0 >> 16);
    r->s1 = (r->s1 & 0xffff) * 0x4650 + (r->s1 >> 16);
    unsigned int v2 = (r->s0 << 16) + (r->s1 & 0xffff);
    Part *p = FUN_0007f310(a1, 1, pick, v2 % n2);
    if (p == 0)
        return;
    p->AddRef();
    p->handle->FUN_001c5080(DAT_00421898, DAT_004218c0);
    p->FUN_00080ea0(&a, &b);
    p->FUN_00080ef0(-1);
    p->FUN_00080f00(a2);
    p->FUN_00080f20(i1);
    p->FUN_00080f30(a4);
    p->FUN_00080e30(&a);
    int cnt = partCount;
    int k0 = p->key0;
    bool have = false;
    if (cnt > 0) {
        int idx = 0;
        do {
            Part *q = parts[idx];
            if (q->key0 == k0 && q->key1 == p->key1) {
                have = parts[idx] != 0;
                break;
            }
            idx++;
        } while (idx < partCount);
    }
    if (!have && cnt != 20) {
        p->AddRef();
        if (parts[cnt] != 0)
            parts[cnt]->Release();
        parts[cnt] = p;
        partCount++;
    }
    p->FUN_00081b20(0);
    p->Release();
}
