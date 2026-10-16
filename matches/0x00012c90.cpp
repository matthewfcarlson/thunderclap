struct Vec {
    int a, b, c;
};
class Obj {
    char pad[0xb0];
    Vec v;

  public:
    Vec* Get(Vec* out);
};
Vec* Obj::Get(Vec* out) {
    *out = v;
    return out;
}