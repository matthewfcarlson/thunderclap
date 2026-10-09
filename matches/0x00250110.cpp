// Same code shape as 0x0024e590 (propagated; names are from that function)
class SeqEvent { public: virtual int vfunc_0(void*); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
namespace audio { class SeqEventNestTrack : public SeqEvent { public: virtual int vfunc_0(void*); char pad[4]; }; }
extern bool __cdecl FUN_0025bce0(void*, void*);
int audio::SeqEventNestTrack::vfunc_0(void* param) {
    if ((unsigned char)SeqEvent::vfunc_0(param)) {
        if (FUN_0025bce0(param, (char*)this + 8)) return 1;
    }
    return 0;
}
