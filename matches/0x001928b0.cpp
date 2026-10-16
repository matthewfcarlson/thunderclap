struct V {
    int a, b, c;
};
class Obj {
    char pad[0x38];
    V v;

  public:
    V* get(V* out);
};
V* Obj::get(V* out) {
    *out = v;
    return out;
}