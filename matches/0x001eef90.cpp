class A_1eef90 {
  public:
    void f(void*, int);
};
A_1eef90* __cdecl make();
void __stdcall target(void* p) {
    A_1eef90* a = make();
    a->f(p, 0);
}