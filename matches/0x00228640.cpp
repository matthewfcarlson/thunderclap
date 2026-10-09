extern "C" void __cdecl Work(int, int*);
extern int gZeroA, gZeroB, gMinusOne;
struct V {
    int a, b, c;
};
class Obj {
  public:
    char pad[0x8a8];
    int value;
    V* Get(V*);
};
V* Obj::Get(V* out) {
    V local;
    local.a = gZeroA;
    local.b = gZeroB;
    local.c = gMinusOne;
    Work(value, (int*)&local);
    *out = local;
    return out;
}
