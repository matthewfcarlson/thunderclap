extern void* stackVftable;
void __cdecl thunk(int);
class pddiStack_31e330 {
  public:
    void* vptr;
    char pad[8];
    int value;
    void f();
};
void pddiStack_31e330::f() {
    int x = value;
    vptr = &stackVftable;
    thunk(x);
}