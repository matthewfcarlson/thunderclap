// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0003b4f0 @ 0x0003b4f0
struct Scene;

struct Camera {
    float FUN_002220d0();
};

struct Scene {
    char pad00[0x10];
    Camera camera;          // 0x10
};

struct Owner {
    Scene *FUN_00059a40();
};

float __cdecl FUN_00224f10(float v);
float __cdecl FUN_00224fc0(float a, float b);

union FloatBits {
    float f;
    unsigned int u;
};

class AimCheck {
public:
    char pad00[0x10];
    Owner *owner;           // 0x10
    char pad14[0x1b5c - 0x14];
    float threshold;        // 0x1b5c
    char pad1b60[0x1b91 - 0x1b60];
    char active;            // 0x1b91
    bool FUN_0003b4f0(float angle);
};

bool AimCheck::FUN_0003b4f0(float angle)
{
    if (!active)
        return false;

    Scene *scene = owner->FUN_00059a40();
    float heading;
    if (scene == 0)
        heading = 0.0f;
    else
        heading = scene->camera.FUN_002220d0();

    FloatBits diff;
    diff.f = FUN_00224fc0(heading, FUN_00224f10(angle) + 3.14159274f);
    diff.u &= 0x7fffffff;
    return !(threshold * 0.5f < diff.f);
}
