struct V {
    int a, b, c;
};
class A {
  public:
    V* get();
};
A* __cdecl fetch();
V* __stdcall FUN(V* out) {
    *out = *fetch()->get();
    return out;
}