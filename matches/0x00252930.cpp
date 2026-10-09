typedef unsigned int u32;
extern char g_seqVarVolumeHeap[];
namespace audio {
class SeqEventType { public: virtual ~SeqEventType(); virtual void f1(); virtual void f2(); virtual void f3(); };
class SeqEventVarVolume { public: void* vptr; u32 pad; float volume; void Init(); };
class SeqEventVarVolumeType : public SeqEventType { public: virtual SeqEventVarVolume* vfunc_3(); };
}
extern "C" audio::SeqEventVarVolume* FUN_00247530(void*);
audio::SeqEventVarVolume* audio::SeqEventVarVolumeType::vfunc_3() {
 audio::SeqEventVarVolume* p = FUN_00247530((void*)g_seqVarVolumeHeap);
 if (p) {
  p->Init();
  p->vptr = (void*)0x429fac;
  p->volume = 1.0f;
  return p;
 }
 return 0;
}
