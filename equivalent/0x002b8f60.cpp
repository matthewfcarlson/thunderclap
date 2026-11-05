// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002b8f60 @ 0x002b8f60
#include "compat/ptr.h"
#include "gen/owners.h"
struct Mat4_2b8f60;

struct Vec3_2b8f60 {
    float x, y, z;
};

struct Mat4_2b8f60 {
    float m[16];
};

class Box_2b8f60 {
public:
    char pad00[0x80];
    float halfX;
    float halfY;
    float depth;
    void FUN_002b8f60(Vec3_2b8f60* corners, Mat4_2b8f60* local, Mat4_2b8f60* world, hulk_intptr unused, float scale);
};

void Box_2b8f60::FUN_002b8f60(Vec3_2b8f60* corners, Mat4_2b8f60* local, Mat4_2b8f60* world, hulk_intptr unused, float scale)
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
        ((owners::Obj_22d210 *)&(corners[i]))->FUN_0022d210((owners::Obj_22d210 *)(Mat4_2b8f60 *)local);
    if (depth != 0.0f) {
        Vec3_2b8f60 u;
        u.x = 0.0f;
        u.y = 0.0f;
        u.z = -depth;
        ((owners::Obj_22d260 *)&u)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b8f60 *)local);
        for (int i = 0; i < 4; i++) {
            corners[i].x += u.x;
            corners[i].y += u.y;
            corners[i].z += u.z;
        }
    }
    for (int i = 0; i < 4; i++)
        ((owners::Obj_22d210 *)&(corners[i]))->FUN_0022d210((owners::Obj_22d210 *)(Mat4_2b8f60 *)world);
}
