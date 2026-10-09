namespace audio {
class ChannelVolumeFadeBehaviour;
}
class DynBehaviour {
  public:
    virtual audio::ChannelVolumeFadeBehaviour* vfunc_0(int);
    virtual void vfunc_1();
};
namespace audio {
class ChannelVolumeFadeBehaviour : public DynBehaviour {
  public:
    virtual ChannelVolumeFadeBehaviour* vfunc_0(int);
    virtual void vfunc_1();
};
} // namespace audio
extern void __cdecl FUN_00247550(void*, void*);
extern int gdata;
audio::ChannelVolumeFadeBehaviour* audio::ChannelVolumeFadeBehaviour::vfunc_0(int x) {
    *(int*)this = 0x42991c;
    if (x & 1)
        FUN_00247550(&gdata, this);
    return this;
}