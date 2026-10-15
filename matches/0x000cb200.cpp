struct Vec3 {
    float x, y, z;
};
class Obj {
  public:
    void fn(int, Vec3);
};
class Wrap {
    char pad[0x88];
    Obj* obj;

  public:
    void fn(int a, Vec3 v);
};
void Wrap::fn(int a, Vec3 v) {
    if (obj)
        obj->fn(a, v);
}