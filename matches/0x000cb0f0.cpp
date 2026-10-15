struct Vec3 {
    float x, y, z;
};
class Target {
  public:
    char pad[0x88];
    class Obj* obj;
    void Fn(int a, int b, Vec3 v);
};
class Obj {
  public:
    void Fn(int a, int b, Vec3 v);
};
void Target::Fn(int a, int b, Vec3 v) {
    if (obj)
        obj->Fn(a, b, v);
}