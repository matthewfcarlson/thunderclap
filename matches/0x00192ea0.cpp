struct V {
    int x, y, z;
};
class Obj {
    char pad[0x11c];
    V v;

  public:
    V* Get(V* out);
};
V* Obj::Get(V* out) {
    *out = v;
    return out;
}