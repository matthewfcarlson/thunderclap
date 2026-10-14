// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 13/13)
// FUN_001e51b0 @ 0x001e51b0
struct Vec3_1e51b0 {
    float x, y, z;
};

struct Entity;

struct Entity {
    char pad00[0x164];
    Vec3_1e51b0 pos;
    int FUN_001d69a0();
    // equiv-conv: FUN_001d6990 ecx stack
    int FUN_001d6990(int extra);
};

char FUN_00202560(Vec3_1e51b0* p, float radius, int a, Vec3_1e51b0* hit, Vec3_1e51b0* normal, int b, int c, int d);
void* FUN_001d68e0(int count);

struct Frame_1e51b0 {
    float tmp;
    Vec3_1e51b0 p;
    Vec3_1e51b0 hit;
    Vec3_1e51b0 normal;
    Vec3_1e51b0 snapped;
    Vec3_1e51b0 corners[4];
};

struct Listener_1e51b0 {
    void FUN_001d7460(Entity* e);
};

class Placer_1e51b0 {
public:
    Vec3_1e51b0* FUN_001dcb00(Vec3_1e51b0* out, Vec3_1e51b0* in);
    Listener_1e51b0* FUN_001e4c40(void* p, Vec3_1e51b0* corners, int count, int a, int b, int c);

    // equiv-conv: FUN_001e51b0 ecx stack esi
    void FUN_001e51b0(Entity* e, int extra);
};

void Placer_1e51b0::FUN_001e51b0(Entity* e, int extra)
{
    Frame_1e51b0 f;

    f.p.x = e->pos.x;
    f.p.y = e->pos.y + 0.5f;
    f.p.z = e->pos.z;
    if (!FUN_00202560(&f.p, 20.0f, 0, &f.hit, &f.normal, 0, 0, 0))
        f.hit = f.p;

    f.p = *FUN_001dcb00(&f.snapped, &f.hit);

    int shape = e->FUN_001d69a0();
    f.corners[0] = f.p;
    f.corners[1] = f.p;
    f.corners[2] = f.p;
    f.corners[3] = f.p;

    switch (shape) {
    case 0:
        return;
    case 2:
        f.corners[0].x = f.p.x + 0.5f;
        f.corners[1].x = f.p.x - 0.5f;
        break;
    case 3:
        f.corners[0].x = f.p.x + 0.5f;
        f.corners[1].x = f.p.x - 0.5f;
        f.corners[1].z = f.p.z - 0.5f;
        f.corners[2].x = f.p.x - 0.5f;
        f.corners[2].z = f.p.z + 0.5f;
        break;
    case 4:
        f.corners[0].x = f.p.x + 0.5f;
        f.corners[0].z = f.p.z + 0.5f;
        f.corners[1].x = f.p.x + 0.5f;
        f.corners[1].z = f.p.z - 0.5f;
        f.corners[2].x = f.p.x - 0.5f;
        f.corners[2].z = f.p.z + 0.5f;
        f.corners[3].x = f.p.x - 0.5f;
        f.corners[3].z = f.p.z - 0.5f;
        break;
    default:
        break;
    }

    int count = e->FUN_001d6990(extra);
    if (count > 0) {
        Listener_1e51b0* l = FUN_001e4c40(FUN_001d68e0(count), f.corners, count, 0, 0, 1);
        if (l)
            l->FUN_001d7460(e);
    }
}
