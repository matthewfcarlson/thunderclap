// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 25/26, incomplete)
// FUN_0007cab0 @ 0x0007cab0
struct Vec3 { float x, y, z; };

struct Matrix {
    float m[16];
};

struct Item {
    char pad0[0x10];
    int type;
    char pad14[0x20];
    int id;
};

struct Position {
    void FUN_00059a50(Vec3 *out);
};

struct Entity {
    char pad0[0x10];
    Position *position;
};

struct Holder {
    char pad0[0x124];
    Entity *entity;
};

struct Manager {
    bool FUN_001dd800(int id);
    void FUN_001dda30(int id, int flag);
    bool FUN_001df4c0(int id);
    bool FUN_001dd520(int id, Matrix *out);
};

struct Context {
    char pad0[0xc];
    Manager *manager;
    char pad10[0x10];
    Holder *holder;
};

class Group {
public:
    char pad0[0x374c];
    Item *items[20];
    int count;
    char pad37a0[0x8c];
    Context *context;
    void FUN_0007cab0(int limit);
};

void Group::FUN_0007cab0(int limit)
{
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (found >= limit)
            break;
        if (items[i]->type == 0x13) {
            if (!context->manager->FUN_001dd800(items[i]->id)) {
                context->manager->FUN_001dda30(items[i]->id, 1);
                found++;
            }
        }
    }

    Vec3 vec;
    context->holder->entity->position->FUN_00059a50(&vec);

    if (found >= limit)
        return;
    for (int i = 0; i < count; i++) {
        if (found >= limit)
            return;
        if (items[i]->type == 0x13) {
            Matrix m;
            context->manager->FUN_001dd520(items[i]->id, &m);
            float dx = vec.x - m.m[12];
            float dz = vec.z - m.m[14];
            bool a = context->manager->FUN_001dd800(items[i]->id);
            bool b = context->manager->FUN_001df4c0(items[i]->id);
            if (a && !b && dz * dz + dx * dx > 1600.0f) {
                context->manager->FUN_001dda30(items[i]->id, 1);
                found++;
            }
        }
    }
}
