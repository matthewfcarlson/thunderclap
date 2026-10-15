struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x88];

  public:
    class Inner* inner;
    void Fn(int, Vec);
};
class Inner {
  public:
    void Fn(int, Vec);
};
void Obj::Fn(int a, Vec v) {
    if (inner)
        inner->Fn(a, v);
}