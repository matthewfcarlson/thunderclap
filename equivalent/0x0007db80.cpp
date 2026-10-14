// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 29/30, incomplete)
// FUN_0007db80 @ 0x0007db80
struct V3_7db80 {
    float x, y, z;
};

struct Rng_7db80 {
    unsigned int a;
    unsigned int b;
};

extern Rng_7db80 *DAT_004e5acc;

static inline unsigned int NextRandom()
{
    Rng_7db80 *r = DAT_004e5acc;
    r->a = (r->a & 0xffff) * 0x9069 + (r->a >> 16);
    r->b = (r->b & 0xffff) * 0x4650 + (r->b >> 16);
    return (r->a << 16) + (r->b & 0xffff);
}

struct Ref_7db80 {
    void FUN_00059a50(V3_7db80 *out);
};

struct Level3_7db80 {
    char pad[0x10];
    Ref_7db80 *ref;
};

struct Level2_7db80 {
    char pad[0x124];
    Level3_7db80 *inner;
};

struct Level1_7db80 {
    char pad[0x20];
    Level2_7db80 *next;
};

struct Item_7db80 {
    V3_7db80 a;
    V3_7db80 b;
    int f18;
    int count;
    int u;
    int v;
    int state;
    char pad2c[0x44 - 0x2c];
    bool flag;
    char pad45[3];
};

class Spawner_7db80 {
public:
    char pad0[0x1904];
    Item_7db80 items[98];
    char pad_rest[0x382c - 0x1904 - sizeof(Item_7db80) * 98];
    Level1_7db80 *owner;

    bool FUN_0007c5b0(V3_7db80 a, V3_7db80 b);
    bool FUN_0007c930(V3_7db80 a, int x);
    void FUN_0007db80(int *outSlot, int *outItem);
};

void Spawner_7db80::FUN_0007db80(int *outSlot, int *outItem)
{
    V3_7db80 pos;
    int cands[14];
    owner->next->inner->ref->FUN_00059a50(&pos);

    int start = NextRandom() % 7;
    for (int i = 0; i < 7; i++) {
        int slot = (i + start) % 7;
        Item_7db80 *group = &items[slot * 14];
        if (group[0].count <= 0)
            continue;
        int n = 0;
        for (int j = 0; j < 14; j++) {
            Item_7db80 *it = &group[j];
            if (!it->flag)
                break;
            float dx = pos.x - it->a.x;
            float dy = pos.y - it->a.y;
            float dz = pos.z - it->a.z;
            if (it->state >= 3)
                continue;
            if (!(dz * dz + dy * dy + dx * dx < 10000.0f))
                continue;
            if (!FUN_0007c5b0(it->a, it->b))
                continue;
            if (it->u != -1 && it->v != -1) {
                Item_7db80 *other = &items[it->u * 14 + it->v];
                if (other->flag && other->state >= 3)
                    continue;
            }
            cands[n] = j;
            n++;
        }
        if (n == 0)
            continue;
        int r = NextRandom() % (unsigned int)n;
        for (int k = 0; k < n; k++) {
            int j = cands[(k + r) % n];
            if (!FUN_0007c930(items[slot * 14 + j].a, -1)) {
                *outSlot = slot;
                *outItem = j;
                return;
            }
        }
    }
    *outSlot = -1;
    *outItem = -1;
}
