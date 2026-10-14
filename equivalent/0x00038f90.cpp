// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_00038f90 @ 0x00038f90
struct Vec3_38f90 { float x, y, z; };

struct Node {
    char data[0x40];
    void FUN_0022c2b0(Vec3_38f90 *src, Vec3_38f90 *out);
};

struct Table_38f90 {
    unsigned int FUN_00044630(int id);
    Vec3_38f90 *FUN_00044650(int id);
    float FUN_000446a0(int id);
};

struct Nodes_38f90 {
    char pad[0x1c];
    Node *items;
};

struct Scene_38f90 { char pad[4]; };
int __fastcall FUN_00059a40(void *x);

extern int DAT_003f5bc4[3];

class Probe_38f90 {
public:
    int FUN_00038f90(Vec3_38f90 *pos, float radius, Vec3_38f90 *out);

    char pad0[0x10];
    void *scene;
    char pad14[0x11c - 0x14];
    Table_38f90 *table;
    Nodes_38f90 *nodes;
};

int Probe_38f90::FUN_00038f90(Vec3_38f90 *pos, float radius, Vec3_38f90 *out)
{
    if (table == 0 || FUN_00059a40(scene) == 0)
        return 0;
    Nodes_38f90 *n = nodes;
    if (n == 0)
        return 0;

    for (int i = 0; i < 3; i++) {
        int id = DAT_003f5bc4[i];
        unsigned int slot = table->FUN_00044630(id);
        if (slot == 0xffff)
            continue;
        Node *node = n->items + slot;
        Vec3_38f90 v;
        node->FUN_0022c2b0(table->FUN_00044650(id), &v);

        Vec3_38f90 d = v;
        d.x = d.x - pos->x;
        d.y = d.y - pos->y;
        d.z = d.z - pos->z;
        float r = table->FUN_000446a0(id) + radius;
        float dist2 = d.z * d.z + d.y * d.y + d.x * d.x;
        if (dist2 < r * r) {
            if (out)
                *out = v;
            return id;
        }
    }
    return 0;
}
