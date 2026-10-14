// cl-flags: /O1
extern void* g_a_3d4a3f[];
struct Sub_3d4a3f {
    void Init() throw();
};
int __stdcall Mk(int a) throw();
class A_3d4a3f {
  public:
    void* vptr;
    int m4;
    char pad[0x14 - 8];
    Sub_3d4a3f sub;
    A_3d4a3f(int a) throw();
};
A_3d4a3f::A_3d4a3f(int a) throw() {
    vptr = g_a_3d4a3f;
    sub.Init();
    m4 = Mk(a);
}
