// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002804f0 @ 0x002804f0
extern "C" double sqrt(double);

struct Vec3_2804f0 {
    float x, y, z;
    void FUN_0022d180();
};

struct Mat4_2804f0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bec0(Vec3_2804f0 *dir, Vec3_2804f0 *up);
    void FUN_0022be40(Vec3_2804f0 *pos);
    void FUN_0022be60(float x, float y, float z);
    void FUN_0022ca90(Mat4_2804f0 *a, Mat4_2804f0 *b);
};

struct Slot_2804f0 {
    int id;
    int pad04;
    Mat4_2804f0 matrix;
    int active;
    char pad4c[0x5c - 0x4c];
    float value;
};

class Holder_2804f0 {
public:
    char pad00[0x18];
    Slot_2804f0 slots[100];
    int FUN_002804f0(int id, Vec3_2804f0 *from, Vec3_2804f0 *to, int unused);
};

int Holder_2804f0::FUN_002804f0(int id, Vec3_2804f0 *from, Vec3_2804f0 *to, int unused)
{
    int i;
    for (i = 0; i < 100; i++) {
        if (slots[i].active != 0 && slots[i].id == id)
            break;
    }
    if (i >= 100)
        return id;

    Vec3_2804f0 dir;
    dir.x = to->x - from->x;
    dir.y = to->y - from->y;
    dir.z = to->z - from->z;
    float lenSq = dir.z * dir.z + dir.y * dir.y + dir.x * dir.x;
    dir.FUN_0022d180();

    Mat4_2804f0 look;
    look.FUN_0022b980();
    Vec3_2804f0 up;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    look.FUN_0022bec0(&dir, &up);
    look.FUN_0022be40(from);

    Mat4_2804f0 scale;
    scale.FUN_0022b980();
    scale.FUN_0022be60(1.0f, 1.0f, (float)sqrt(lenSq));

    Mat4_2804f0 result;
    result.FUN_0022ca90(&scale, &look);
    slots[i].matrix = result;
    slots[i].value = 1000.0f;
    return id;
}
