extern "C" char DAT_004298fc[];
extern "C" char DAT_004e7570[];
namespace audio {
class SeqActionClip {
  public:
    unsigned long vt;
    SeqActionClip* vfunc_0(int);
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::SeqActionClip* audio::SeqActionClip::vfunc_0(int f) {
    SeqActionClip* p = this;
    vt = ((int)DAT_004298fc);
    if (f & 1)
        FUN_00247550((void*)((int)DAT_004e7570), p);
    return p;
}