// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 33/34, incomplete)
// FUN_0007a8f0 @ 0x0007a8f0
struct Vec3 {
    float x, y, z;
};

struct Transform {
    void FUN_00059a50(Vec3 *out);
};

struct Holder {
    char pad0[0x10];
    Transform *transform;
};

struct Table {
    char pad0[0x124];
    Holder *player;
};

struct Handle {
    int a;
    int b;
    Handle *FUN_0027af30(const Handle *src);
    void FUN_0027af50();
};

struct Item {
    char pad0[0x14];
    int count;
    Vec3 *FUN_00106160(int index);
};

struct Mgr {
    int FUN_00106290(int a, int b);
    Item *FUN_00106210(int id);
};

struct World {
    char pad0[0x18];
    Mgr *mgr;
    char pad1c[4];
    Table *table;
};

int __cdecl FUN_000113e0(int lo, int hi);

class Finder {
public:
    int FUN_0007a8f0(int *outIndex, int *outSide);

    char pad0[0x35a0];
    Handle handles[(0x3640 - 0x35a0) / 8];
    int count;
    char pad3644[0x382c - 0x3644];
    World *world;
};

int Finder::FUN_0007a8f0(int *outIndex, int *outSide)
{
    if (count < 1)
        return -1;
    Mgr *mgr = world->mgr;
    int start = FUN_000113e0(0, count - 1);
    for (int i = 0; i < count; i++) {
        Handle key;
        key.FUN_0027af30(&handles[(unsigned int)(start + i) % (unsigned int)count]);
        int id = mgr->FUN_00106290(key.a, key.b);
        if (id != -1) {
            Item *item = mgr->FUN_00106210(id);
            if (item != 0) {
                Vec3 player;
                world->table->player->transform->FUN_00059a50(&player);
                int first = FUN_000113e0(0, item->count - 1);
                for (int j = 0; j < item->count; j++) {
                    int cur = (first + j) % item->count;
                    Vec3 p = *item->FUN_00106160(cur);
                    double dx = p.x - player.x;
                    double dz = p.z - player.z;
                    double d2 = dz * dz + dx * dx;
                    bool inFar = d2 < 4900.0f;
                    bool inNear = d2 < 2500.0f;

                    Vec3 *q = item->FUN_00106160((cur + 1) % item->count);
                    p.x = q->x - player.x;
                    double dz2 = q->z - player.z;
                    double d3 = dz2 * dz2 + p.x * p.x;
                    bool inFar2 = d3 < 4900.0f;
                    bool inNear2 = d3 < 2500.0f;

                    if (inFar && !inNear && inNear2) {
                        *outSide = 0;
                        *outIndex = cur;
                        key.FUN_0027af50();
                        return id;
                    }
                    if (inFar2 && !inNear2 && inNear) {
                        *outSide = 1;
                        *outIndex = cur;
                        key.FUN_0027af50();
                        return id;
                    }
                }
            }
        }
        key.FUN_0027af50();
    }
    return -1;
}
