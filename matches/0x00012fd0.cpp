struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0xe0];
    Vec vec;

  public:
    Vec* Get(Vec* out);
};
Vec* Obj::Get(Vec* out) {
    *out = vec;
    return out;
}