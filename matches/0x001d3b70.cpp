extern "C" void __cdecl FUN_001d22a0();
typedef unsigned int u32_1d3b70;
class A_1d3b70 {
  public:
    void f(u32_1d3b70);
};
class B_1d3b70 {
  public:
    void f(u32_1d3b70);
};
class Obj_1d3b70 {
  public:
    char pad[8];
    void* field8;
    char pad2[4];
    void run(u32_1d3b70 a, u32_1d3b70 b);
};
void __cdecl F3(void*, u32_1d3b70);
void __cdecl F4(void*, void*, int);
void __cdecl F5(void*, int, u32_1d3b70);
void Obj_1d3b70::run(u32_1d3b70 a, u32_1d3b70 b) {
    ((A_1d3b70*)b)->f(a);
    ((B_1d3b70*)((char*)this + 0xc))->f(b);
    void* x = field8;
    F3(x, b);
    F4(x, (void*)((int)(void (__cdecl*)())&FUN_001d22a0), 1);
    F5(x, 0xffffd8ef, a);
}
