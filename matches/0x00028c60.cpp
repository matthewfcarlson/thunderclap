typedef unsigned __int64 U64;
U64 __cdecl getValue(int, int, int);
class Obj {
  public:
    char pad[0x20b0];
    int value;
};
class Target {
  public:
    Obj* lookup(U64);
    int run(int);
};
int Target::run(int x) {
    U64 v = getValue(x, 0, 0);
    Obj* o = lookup(v);
    if (!o)
        return -1;
    return o->value;
}
