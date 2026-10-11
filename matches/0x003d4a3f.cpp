// cl-flags: /O1
extern void* g_a[];
struct Sub {
    void Init() throw();
};
int __stdcall Mk(int a) throw();
class A {
  public:
    void* vptr;
    int m4;
    char pad[0x14 - 8];
    Sub sub;
    A(int a) throw();
};
A::A(int a) throw() {
    vptr = g_a;
    sub.Init();
    m4 = Mk(a);
}
