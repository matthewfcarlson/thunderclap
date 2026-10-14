extern "C" void __cdecl Work(int, int*);
extern int gZeroA, gZeroB, gMinusOne;
struct V {
    int a, b, c;
};
class Obj_228640 {
  public:
    char pad[0x8a8];
    int value;
    V* Get(V*);
};
V* Obj_228640::Get(V* out) {
    V local;
    local.a = gZeroA;
    local.b = gZeroB;
    local.c = gMinusOne;
    Work(value, (int*)&local);
    *out = local;
    return out;
}
