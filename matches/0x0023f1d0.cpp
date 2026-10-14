typedef unsigned int u32_23f1d0;
typedef unsigned char u8_23f1d0;
extern u32_23f1d0 g_fn;
extern u32_23f1d0 g_arg;
class BreakPointAction {
    char pad[0x20];

  public:
    u32_23f1d0 member;
    u8_23f1d0 vfunc_3(u32_23f1d0 a, u32_23f1d0 b);
};
u8_23f1d0 BreakPointAction::vfunc_3(u32_23f1d0 a, u32_23f1d0 b) {
    if (g_fn) {
        typedef void(__cdecl * Fn)(u32_23f1d0, u32_23f1d0);
        ((Fn)g_fn)(member, g_arg);
    }
    return 0;
}