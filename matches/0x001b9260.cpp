struct Vec {
    int x, y, z;
};
class A {
  public:
    Vec* get();
};
A* __cdecl findA();
Vec __stdcall target() {
    A* a = findA();
    return *a->get();
}