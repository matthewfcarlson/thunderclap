struct Obj {
    char pad[0x1d24];
    float value;
};
class C {
  public:
    Obj* Find(int lo, int hi);
    float Get(int id);
};
struct Pair {
    int lo, hi;
};
Pair __cdecl Lookup(int id, int a, int b);
float C::Get(int id) {
    Pair p = Lookup(id, 0, 0);
    Obj* o = Find(p.lo, p.hi);
    if (!o)
        return 1.0f;
    return o->value;
}