// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::CollisionCylinder::vfunc_9 @ 0x002f3270
extern "C" double __cdecl sqrt(double);
namespace physics {
struct CollisionVolume {
    char padding[0x34];
    float extent;
    void vfunc_9();
};
struct CollisionCylinder : CollisionVolume {
    char padding2[0x50 - 0x38];
    float radius;
    float halfHeight;
    unsigned char roundEnds;
    void vfunc_9();
};
void CollisionCylinder::vfunc_9() {
    if (roundEnds) {
        float r = radius;
        float h = halfHeight;
        extent = (float)sqrt(r*r + h*h);
    } else {
        extent = halfHeight + radius;
    }
    CollisionVolume::vfunc_9();
}
}