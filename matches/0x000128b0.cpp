struct Vec {
    int x, y, z;
};
class Obj {
    char pad[16];
    Vec v;

  public:
    Vec Get();
};
Vec Obj::Get() {
    return v;
}