// b..d: a vector passed by value (the caller passes a math::Vector).
struct Vec3_1f7280 {
    float x, y, z;
};
class Obj_1f7280 {
  public:
    void Act(int, Vec3_1f7280*);
};
Obj_1f7280* Get();
class Host_1f7280 {
  public:
    unsigned char target(int a, Vec3_1f7280 b);
};
unsigned char Host_1f7280::target(int a, Vec3_1f7280 b) {
    if (a < 0)
        return 0;
    Obj_1f7280* p = Get();
    if (p)
        p->Act(a, &b);
    return 1;
}