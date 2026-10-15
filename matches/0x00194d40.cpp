struct Vec {
    float x, y, z;
    Vec() : x(0.0f), y(0.0f), z(0.0f) {}
};
struct Obj {
    char pad[0x40];
    Vec v;
};
class ProjectileGroundShockwave {
  public:
    char pad[0x24];
    Obj* obj;
    Vec* vfunc_3();
};
Vec* ProjectileGroundShockwave::vfunc_3() {
    if (!obj) {
        static Vec zero;
        return &zero;
    }
    return &obj->v;
}