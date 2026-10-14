// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00035810 @ 0x00035810
extern float DAT_003f32e0;
struct Vec3 { int x, y, z; float FUN_0022d110(); };
struct Mover {
    char pad0[0x1e4];
    float duration;
    Vec3 delta;
    float speed, decel;
    int busy;
    void Start(float t, const Vec3* d);
};
void Mover::Start(float t, const Vec3* d) {
    if (busy > 0 || !(t > DAT_003f32e0)) return;
    duration = t;
    delta.x = d->x; delta.y = d->y; delta.z = d->z;
    delta.y = 0;
    float len = delta.FUN_0022d110();
    speed = len + len;
    decel = ((len * duration - (len + len) * duration) * 2.0f) / (duration * duration);
}
