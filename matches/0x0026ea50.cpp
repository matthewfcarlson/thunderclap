extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b474[];
extern "C" char DAT_0042b47c[];
extern "C" char DAT_004cdbb0[];
extern "C" char DAT_005283b0[];
typedef unsigned int u32;
extern "C" void init_console();
extern "C" void cleanup_console(u32, void*);
class ConsoleClient {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[4];
    u32 field8;
    ConsoleClient* vfunc_2(unsigned char);
};
ConsoleClient* ConsoleClient::vfunc_2(unsigned char flag) {
    *(u32*)this = ((int)DAT_0042b47c);
    *(u32*)((char*)this + 4) = ((int)DAT_0042b474);
    init_console();
    *(u32*)((int)DAT_004cdbb0) = field8;
    *(u32*)((char*)this + 4) = ((int)DAT_0042af64);
    *(u32*)((int)DAT_005283b0) = 0;
    *(u32*)this = ((int)DAT_003f6098);
    if (flag & 1)
        cleanup_console(*(u32*)((int)DAT_004cdbb0), this);
    return this;
}