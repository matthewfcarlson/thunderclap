// Same code shape as 0x00242070 (propagated; names are from that function)
typedef unsigned int u32_2559e0;
extern "C" void* __cdecl FUN_00247530(void*);
struct Callee_2559e0 {
    u32_2559e0 run();
};
extern char g_data_2559e0[];
namespace audio {
class MixType {
  public:
    virtual void f0();
    virtual void f1();
    virtual u32_2559e0 vfunc_2();
};
u32_2559e0 MixType::vfunc_2() {
    void* p = FUN_00247530(g_data_2559e0);
    if (p)
        return ((Callee_2559e0*)p)->run();
    return 0;
}
} // namespace audio