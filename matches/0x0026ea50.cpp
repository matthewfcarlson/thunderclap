typedef unsigned int u32;
extern "C" void init_console();
extern "C" void cleanup_console(u32, void*);
class ConsoleClient { public: virtual void v0(); virtual void v1(); virtual void v2(); char pad[4]; u32 field8; ConsoleClient* vfunc_2(unsigned char); };
ConsoleClient* ConsoleClient::vfunc_2(unsigned char flag) {
    *(u32*)this = 0x42b47c;
    *(u32*)((char*)this+4) = 0x42b474;
    init_console();
    *(u32*)0x4cdbb0 = field8;
    *(u32*)((char*)this+4) = 0x42af64;
    *(u32*)0x5283b0 = 0;
    *(u32*)this = 0x3f6098;
    if (flag & 1) cleanup_console(*(u32*)0x4cdbb0, this);
    return this;
}