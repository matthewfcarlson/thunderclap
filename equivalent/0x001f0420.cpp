// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 14/14)
// CSoundCommand_SetLoopPitchEvent::vfunc_1 @ 0x001f0420
struct SoundKey { unsigned int low, high; };
struct LoopState { SoundKey key; unsigned int eventId; unsigned char pitchActive; char pad[3]; float pitch; float pitchStep; char rest[16]; };
struct SoundInstance { char pad[0x80]; LoopState loops[4]; };
struct Lookup_1f0420 { int FUN_001e98b0(SoundKey*); };
struct Instances { SoundInstance* FUN_001f31a0(unsigned int); };
struct SoundSystem_1f0420 { Instances* instances; Lookup_1f0420* lookup; };
extern SoundSystem_1f0420* DAT_004e370c;
struct CSoundCommand { virtual void vfunc_0(); virtual unsigned int vfunc_1(unsigned int, unsigned int); char pad[12]; };
struct CSoundCommand_SetLoopPitchEvent : CSoundCommand {
 SoundKey key; unsigned int eventId; float pitch; float duration;
 virtual void vfunc_0(); virtual unsigned int vfunc_1(unsigned int instanceId, unsigned int unused);
};
unsigned int CSoundCommand_SetLoopPitchEvent::vfunc_1(unsigned int instanceId, unsigned int unused) {
 if (!DAT_004e370c->lookup->FUN_001e98b0(&key)) return 0;
 SoundInstance* instance = DAT_004e370c->instances->FUN_001f31a0(instanceId);
 if (!instance) return 0;
 for (int i=0; i<4; ++i) {
  LoopState& loop = instance->loops[i];
  if (loop.eventId == eventId && loop.key.low == key.low && loop.key.high == key.high) {
   loop.pitchActive = 1; loop.pitch = pitch;
   unsigned int status;
   if (duration < 0.01f) { loop.pitchStep = 0.0f; status = 0x100; }
   else {
    if (duration == 0.01f) status = 0x4000;
    else if (duration > 0.01f) status = 0;
    else status = 0x4500;
    loop.pitchStep = (pitch - 1.0f) / (duration * 16.666666f);
   }
   return ((unsigned int)instance & 0xffff0000U) | status;
  }
 }
 return (unsigned int)instance;
}
