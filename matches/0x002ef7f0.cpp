extern void* vA[];
extern "C" void _ReadWriteBarrier();
struct Sub_2ef7f0 {
    char pad[0x40];
    void Init() throw();
};
class O_2ef7f0 {
  public:
    void* vptr;
    int m4, m8, mc;
    Sub_2ef7f0 sub;
    int m50, m54, m58, m5c, m60, m64;
    float f68;
    int m6c, m70, m74;
    char c78;
    int m7c, m80;
    char c84, c85;
    O_2ef7f0(int a) throw();
};
O_2ef7f0::O_2ef7f0(int a) throw() {
    int t = *(volatile int*)&a;
    m4 = 0;
    vptr = vA;
    m8 = 0;
    mc = 0;
    m50 = 0;
    m54 = 0;
    m58 = 0;
    m5c = 0;
    m60 = 0;
    m64 = 0;
    _ReadWriteBarrier();
    m6c = t;
    f68 = 1.0f;
    m70 = 0;
    m74 = 0;
    c78 = 0;
    m7c = 0;
    m80 = 0;
    c84 = 0;
    c85 = 0;
    sub.Init();
}
