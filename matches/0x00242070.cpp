typedef unsigned int u32_242070;
extern "C" void* __cdecl FUN_00247530(void*);
struct Callee_242070 {
    u32_242070 run();
};
extern char g_data_242070[];
namespace audio {
class MixType {
  public:
    virtual void f0();
    virtual void f1();
    virtual u32_242070 vfunc_2();
};
u32_242070 MixType::vfunc_2() {
    void* p = FUN_00247530(g_data_242070);
    if (p)
        return ((Callee_242070*)p)->run();
    return 0;
}
} // namespace audio