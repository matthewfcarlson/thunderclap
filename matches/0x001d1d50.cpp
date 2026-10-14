struct Obj_1d1d50 {
    char pad[8];
    void* m;
};
extern void __cdecl f(void*, unsigned int);
extern void __cdecl g(void*, int);
class Thing_1d1d50 {
  public:
    bool Run(unsigned int a, unsigned int b);
    char pad[8];
    void* m;
};
bool Thing_1d1d50::Run(unsigned int a, unsigned int b) {
    f(m, a);
    f(m, b);
    g(m, -3);
    return true;
}
