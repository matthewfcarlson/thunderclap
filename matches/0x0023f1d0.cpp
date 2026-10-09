typedef unsigned int u32;
typedef unsigned char u8;
extern u32 g_fn;
extern u32 g_arg;
class BreakPointAction {
    char pad[0x20];

  public:
    u32 member;
    u8 vfunc_3(u32 a, u32 b);
};
u8 BreakPointAction::vfunc_3(u32 a, u32 b) {
    if (g_fn) {
        typedef void(__cdecl * Fn)(u32, u32);
        ((Fn)g_fn)(member, g_arg);
    }
    return 0;
}