// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002804f0 @ 0x002804f0
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    void FUN_0022d180();
};

struct Mat4 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bec0(Vec3 *dir, Vec3 *up);
    void FUN_0022be40(Vec3 *pos);
    void FUN_0022be60(float x, float y, float z);
    void FUN_0022ca90(Mat4 *a, Mat4 *b);
};

struct Slot {
    int id;
    int pad04;
    Mat4 matrix;
    int active;
    char pad4c[0x5c - 0x4c];
    float value;
};

class Holder {
public:
    char pad00[0x18];
    Slot slots[100];
    int FUN_002804f0(int id, Vec3 *from, Vec3 *to, int unused);
};

int Holder::FUN_002804f0(int id, Vec3 *from, Vec3 *to, int unused)
{
    int i;
    for (i = 0; i < 100; i++) {
        if (slots[i].active != 0 && slots[i].id == id)
            break;
    }
    if (i >= 100)
        return id;

    Vec3 dir;
    dir.x = to->x - from->x;
    dir.y = to->y - from->y;
    dir.z = to->z - from->z;
    float lenSq = dir.z * dir.z + dir.y * dir.y + dir.x * dir.x;
    dir.FUN_0022d180();

    Mat4 look;
    look.FUN_0022b980();
    Vec3 up;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    look.FUN_0022bec0(&dir, &up);
    look.FUN_0022be40(from);

    Mat4 scale;
    scale.FUN_0022b980();
    scale.FUN_0022be60(1.0f, 1.0f, (float)sqrt(lenSq));

    Mat4 result;
    result.FUN_0022ca90(&scale, &look);
    slots[i].matrix = result;
    slots[i].value = 1000.0f;
    return id;
}
