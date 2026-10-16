// STATUS: equivalent (tools/equiv.py level 3: 18606 inputs, branch coverage 34/34)
// FUN_0007a8f0 @ 0x0007a8f0
struct Vec3_7a8f0 {
    float x, y, z;
};

struct Transform_7a8f0 {
    void FUN_00059a50(Vec3_7a8f0 *out);
};

struct Holder_7a8f0 {
    char pad0[0x10];
    Transform_7a8f0 *transform;
};

struct Table_7a8f0 {
    char pad0[0x124];
    Holder_7a8f0 *player;
};

struct Handle_7a8f0 {
    int a;
    int b;
    Handle_7a8f0 *FUN_0027af30(const Handle_7a8f0 *src);
    void FUN_0027af50();
};

struct Item_7a8f0 {
    char pad0[0x14];
    int count;
    Vec3_7a8f0 *FUN_00106160(int index);
};

struct Mgr_7a8f0 {
    int FUN_00106290(int a, int b);
    Item_7a8f0 *FUN_00106210(int id);
};

struct World {
    char pad0[0x18];
    Mgr_7a8f0 *mgr;
    char pad1c[4];
    Table_7a8f0 *table;
};

int __cdecl FUN_000113e0(int lo, int hi);
extern float DAT_0049b8e4;  // 2500 (50^2)
extern float DAT_0049b8e8;  // 4900 (70^2)

class Finder_7a8f0 {
public:
    int FUN_0007a8f0(int *outIndex, int *outSide);

    char pad0[0x35a0];
    Handle_7a8f0 handles[(0x3640 - 0x35a0) / 8];
    int count;
    char pad3644[0x382c - 0x3644];
    World *world;
};

int Finder_7a8f0::FUN_0007a8f0(int *outIndex, int *outSide)
{
    if (count < 1)
        return -1;
    Mgr_7a8f0 *mgr = world->mgr;
    int start = FUN_000113e0(0, count - 1);
    for (int i = 0; i < count; i++) {
        Handle_7a8f0 key;
        key.FUN_0027af30(&handles[(unsigned int)(start + i) % (unsigned int)count]);
        int id = mgr->FUN_00106290(key.a, key.b);
        if (id != -1) {
            Item_7a8f0 *item = mgr->FUN_00106210(id);
            if (item != 0) {
                Vec3_7a8f0 player;
                world->table->player->transform->FUN_00059a50(&player);
                int first = FUN_000113e0(0, item->count - 1);
                for (int j = 0; j < item->count; j++) {
                    int cur = (first + j) % item->count;
                    Vec3_7a8f0 p = *item->FUN_00106160(cur);
                    double dx = p.x - player.x;
                    double dz = p.z - player.z;
                    double d2 = dz * dz + dx * dx;
                    bool inFar = d2 < DAT_0049b8e8;
                    bool inNear = d2 < DAT_0049b8e4;

                    Vec3_7a8f0 *q = item->FUN_00106160((cur + 1) % item->count);
                    // the original rounds the x difference to float (stored in p.x) but keeps z on the FPU stack
                    float dz2 = q->z;
                    p.x = q->x - player.x;
                    double d3 = (dz2 - player.z) * (dz2 - player.z) + p.x * p.x;
                    bool inFar2 = d3 < DAT_0049b8e8;
                    bool inNear2 = d3 < DAT_0049b8e4;

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
