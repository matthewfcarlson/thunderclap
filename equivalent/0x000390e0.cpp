// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 16/16)
// FUN_000390e0 @ 0x000390e0
struct Vec3 { float x, y, z; };

struct Mat {
    float m[16];
    void FUN_0022c2b0(const Vec3* in, Vec3* out);
};

struct Holder {
    int FUN_00059a40();
};

struct BoneTable {
    char pad[0xa0];
    int FUN_00044630(int id);
    Vec3* FUN_00044650(int id);
    float FUN_000446a0(int id);
};

struct Skeleton {
    char pad[0x1c];
    Mat* matrices;
};

extern int DAT_003f5bc4[3];

class Probe {
  public:
    char pad0[0x10];
    Holder* holder;
    char pad1[0x11c - 0x14];
    BoneTable* table;
    Skeleton* skeleton;
    int FUN_000390e0(const Vec3* origin, const Vec3* dir, float extra, Vec3* out);
};

int Probe::FUN_000390e0(const Vec3* origin, const Vec3* dir, float extra, Vec3* out) {
    if (table == 0 || holder->FUN_00059a40() == 0)
        return 0;
    Skeleton* skel = skeleton;
    if (skel == 0)
        return 0;
    for (int i = 0; i < 3; i++) {
        int id = DAT_003f5bc4[i];
        int bone = table->FUN_00044630(id);
        if (bone == 0xffff)
            continue;
        Vec3 pos;
        Mat* m = skel->matrices + bone;
        m->FUN_0022c2b0(table->FUN_00044650(id), &pos);
        Vec3 d;
        d.x = pos.x - origin->x;
        d.y = pos.y - origin->y;
        d.z = pos.z - origin->z;
        float dot = d.y * dir->y + d.z * dir->z + d.x * dir->x;
        if (!(dot <= 0.0f)) {
            float len2 = dir->y * dir->y + dir->z * dir->z + dir->x * dir->x;
            if (dot < len2) {
                float t = -(dot / len2);
                d.x = t * dir->x + d.x;
                d.y = t * dir->y + d.y;
                d.z = t * dir->z + d.z;
            } else {
                d.x = d.x - dir->x;
                d.y = d.y - dir->y;
                d.z = d.z - dir->z;
            }
        }
        float radius = table->FUN_000446a0(id) + extra;
        if (radius * radius > d.z * d.z + d.x * d.x + d.y * d.y) {
            *out = pos;
            return id;
        }
    }
    return 0;
}
