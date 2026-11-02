class A_1eef90 {
  public:
    void f(void*, int);
};
extern "C" A_1eef90* __cdecl FUN_001d4c90();
void __stdcall target(void* p) {
    A_1eef90* a = FUN_001d4c90();
    a->f(p, 0);
}