extern void* stackVftable;
void __cdecl thunk(int);
class Obj {
  public:
    void* vptr;
    char pad[8];
    int value;
    void f();
};
void Obj::f() {
    int x = value;
    vptr = &stackVftable;
    thunk(x);
}