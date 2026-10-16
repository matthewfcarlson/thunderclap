struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0xa4];
    Vec v;

  public:
    Vec Get();
};
Vec Obj::Get() {
    return v;
}