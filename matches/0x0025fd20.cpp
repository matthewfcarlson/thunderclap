typedef unsigned int u32_25fd20;
namespace audio {
class SeqEvent {
  public:
    virtual int vfunc_0(u32_25fd20);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
} // namespace audio
extern int FUN_00263db0(u32_25fd20, u32_25fd20);
int audio::SeqEvent::vfunc_0(u32_25fd20 param_1) {
    return FUN_00263db0(param_1, 0);
}