class A {
  public:
    void f(void*, int);
};
A* __cdecl make();
void __stdcall target(void* p) {
    A* a = make();
    a->f(p, 0);
}