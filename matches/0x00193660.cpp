struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0x118];
    Vec v;

  public:
    Vec* Get(Vec* out);
};
Vec* Obj::Get(Vec* out) {
    *out = v;
    return out;
}