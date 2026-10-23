struct V {
    int a, b, c;
};
class A {
  public:
    V* Get();
};
A* __cdecl FUN_001c3d90();
V __stdcall target() {
    return *FUN_001c3d90()->Get();
}