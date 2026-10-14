// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 24/28, incomplete)
// FUN_002ff530 @ 0x002ff530
struct Vec3_2ff530 { float x, y, z; };

struct Shape_2ff530 {
    char pad0[0x10];
    int f10;
};

struct Hit_2ff530 {
    int f0;
    int f4;
    Shape_2ff530 *shape;
};

struct Elem_2ff530 {
    char pad0[0x20];
    Shape_2ff530 *shape;
    char pad24[0x50 - 0x24];
    unsigned char flag50;
    char pad51[0x72 - 0x51];
    unsigned char flag72;
};

extern "C" bool FUN_002f0780(Vec3_2ff530 a, Vec3_2ff530 b, Vec3_2ff530 *c, Vec3_2ff530 d, int e, int f);
extern "C" bool FUN_002f1160(void *a, int b, Vec3_2ff530 *c, int d, Hit_2ff530 *out);
extern "C" void FUN_002f24f0(void *a, Hit_2ff530 *hit, int b, Vec3_2ff530 *c, int *d);

struct Group_2ff530 {
    Elem_2ff530 **begin;
    Elem_2ff530 **end;
    char pad8[0x50 - 8];
    unsigned char active;
    char pad51[3];
    Vec3_2ff530 v54;
    Vec3_2ff530 v60;
    void Run(void *a0, Vec3_2ff530 *a1, int a2, Vec3_2ff530 *a3, int *a4, bool a5);
};

void Group_2ff530::Run(void *a0, Vec3_2ff530 *a1, int a2, Vec3_2ff530 *a3, int *a4, bool a5)
{
    if (!active)
        return;

    Hit_2ff530 hit;
    hit.f0 = 0;
    hit.f4 = 0;
    hit.shape = 0;

    if (!(v54.x == 0.0f && v54.y == 0.0f && v54.z == 0.0f &&
          v60.x == 0.0f && v60.y == 0.0f && v60.z == 0.0f)) {
        Vec3_2ff530 sum;
        sum.x = a1->x + a3->x;
        sum.y = a1->y + a3->y;
        sum.z = a1->z + a3->z;
        if (!FUN_002f0780(*a1, sum, &v54, v60, 0, 0))
            return;
    }

    unsigned int i = 0;
    while (i < (unsigned int)(end - begin)) {
        Elem_2ff530 *e = begin[i];
        hit.shape = e->shape;
        if (e->flag72 && (!a5 || e->flag50)) {
            if (FUN_002f1160(a1, a2, a3, *a4, &hit)) {
                hit.f4 = hit.shape->f10;
                FUN_002f24f0(a0, &hit, a2, a3, a4);
            }
        }
        i++;
    }
}
