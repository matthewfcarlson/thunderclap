struct V {
    int a, b, c;
};
class A {
  public:
    V* Get();
};
A* __cdecl make();
V __stdcall target() {
    return *make()->Get();
}