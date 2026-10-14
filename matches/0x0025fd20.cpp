typedef unsigned int u32_25fd20;
namespace audio {
class SeqEvent {
  public:
    virtual void vfunc_0(u32_25fd20);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
} // namespace audio
extern void FUN_00263db0(u32_25fd20, u32_25fd20);
void audio::SeqEvent::vfunc_0(u32_25fd20 param_1) {
    FUN_00263db0(param_1, 0);
}