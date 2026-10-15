class Obj {
  public:
    char pad[0x1b0c];
    float value;
};
class C {
  public:
    Obj* lookup(__int64);
    float get(int id);
};
extern "C" __int64 __cdecl find(int, int, int);
extern const float zero;
float C::get(int id) {
    __int64 x = find(id, 0, 0);
    Obj* p = lookup(x);
    if (!p)
        return zero;
    return p->value;
}