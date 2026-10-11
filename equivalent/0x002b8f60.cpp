// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002b8f60 @ 0x002b8f60
struct Mat4;

struct Vec3 {
    float x, y, z;
    void FUN_0022d210(Mat4* m);
    void FUN_0022d260(Mat4* m);
};

struct Mat4 {
    float m[16];
};

class Box {
public:
    char pad00[0x80];
    float halfX;
    float halfY;
    float depth;
    void FUN_002b8f60(Vec3* corners, Mat4* local, Mat4* world, int unused, float scale);
};

void Box::FUN_002b8f60(Vec3* corners, Mat4* local, Mat4* world, int unused, float scale)
{
    float x = scale * halfX;
    float y = scale * halfY;
    corners[0].x = -x;
    corners[0].y = -y;
    corners[0].z = 0.0f;
    corners[1].x = x;
    corners[1].y = -y;
    corners[1].z = 0.0f;
    corners[2].x = x;
    corners[2].y = y;
    corners[2].z = 0.0f;
    corners[3].x = -x;
    corners[3].y = y;
    corners[3].z = 0.0f;
    for (int i = 0; i < 4; i++)
        corners[i].FUN_0022d210(local);
    if (depth != 0.0f) {
        Vec3 u;
        u.x = 0.0f;
        u.y = 0.0f;
        u.z = -depth;
        u.FUN_0022d260(local);
        for (int i = 0; i < 4; i++) {
            corners[i].x += u.x;
            corners[i].y += u.y;
            corners[i].z += u.z;
        }
    }
    for (int i = 0; i < 4; i++)
        corners[i].FUN_0022d210(world);
}
