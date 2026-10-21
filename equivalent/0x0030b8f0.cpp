// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 14/14)
// physics::PhysicsJoint3D::vfunc_25 @ 0x0030b8f0
#include "decls/data/engine/physics.h"
#include "compat/ptr.h"

extern "C" double sqrt(double);

class Joint3D {
public:
    int vptr;
    char pad04[0x0c];
    float minSpeed;
    float maxSpeed;
    char pad18[0x80];
    float axis[3];
    char padA4[0x7c];
    float dir[3];
    char pad12c[0x0c];
    float impulse[3];
    char pad144[0x10];
    float speed;
    float slip;

    void FUN_0030b8f0();
};

void Joint3D::FUN_0030b8f0()
{
    hulk_freg lenSq = (dir[0] * dir[0] + dir[1] * dir[1]) + dir[2] * dir[2];
    if (lenSq > (*(const float*)&DAT_004d31d4)) {
        hulk_freg s = (*(const float*)&DAT_004d3198) / (float)sqrt(lenSq);
        dir[0] = dir[0] * s;
        dir[1] = dir[1] * s;
        dir[2] = dir[2] * s;
    }

    if (!(*(const bool*)&DAT_004d319c))
        return;

    float a = slip < 0.0f ? -slip : slip;
    if (a > (*(const float*)&DAT_004d3194)) {
        float t;
        if (slip > 0.0f)
            t = slip - (*(const float*)&DAT_004d3194);
        else
            t = (*(const float*)&DAT_004d3194) + slip;
        t = t * (*(const float*)&DAT_004d31a0);
        float nt = -t;
        impulse[0] = nt * axis[0] + impulse[0];
        impulse[1] = nt * axis[1] + impulse[1];
        impulse[2] = nt * axis[2] + impulse[2];
        slip = slip - t;
    }

    if (speed > maxSpeed) {
        hulk_freg r = maxSpeed / speed;
        impulse[0] = impulse[0] * r;
        impulse[1] = impulse[1] * r;
        impulse[2] = impulse[2] * r;
        speed = maxSpeed;
    } else if (speed < minSpeed && minSpeed < 0.0f) {
        hulk_freg r = maxSpeed / speed;
        impulse[0] = impulse[0] * r;
        impulse[1] = impulse[1] * r;
        impulse[2] = impulse[2] * r;
        speed = minSpeed;
    }
}
