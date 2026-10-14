extern void* g_vt_fed00[];
extern void* g_vt2[];
struct Sub_fed00 {
    void* vptr;
    void Init() throw();
};
class A_fed00 {
  public:
    void* vptr;
    int m4, m8;
    int mc[16];
    int m4c, m50;
    char pad[0x58 - 0x54];
    Sub_fed00 sub;
    char pad2[0xe8 - 0x58 - 4];
    char me8, me9;
    char pad3[0xf0 - 0xea];
    int mf0;
    char mf4;
    A_fed00() throw();
};
A_fed00::A_fed00() throw() {
    m4 = 0;
    vptr = g_vt_fed00;
    m8 = 0;
    m4c = -1;
    m50 = -1;
    sub.vptr = g_vt2;
    sub.Init();
    me8 = 0;
    me9 = 1;
    for (int i = 0; i < 16; i++)
        mc[i] = 0;
    mf0 = 1;
    mf4 = 0;
}
