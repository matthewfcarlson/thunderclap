namespace om {
class DynBehaviour {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
} // namespace om
namespace audio {
class ChannelSendVolumeFadeBehaviour : public om::DynBehaviour {
  public:
    virtual ChannelSendVolumeFadeBehaviour* vfunc_0(int);
    virtual void vfunc_1();
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::ChannelSendVolumeFadeBehaviour* audio::ChannelSendVolumeFadeBehaviour::vfunc_0(int flag) {
    ChannelSendVolumeFadeBehaviour* p = this;
    *(int*)p = 0x42991c;
    if (flag & 1)
        FUN_00247550((void*)0x4e67b8, p);
    return p;
}