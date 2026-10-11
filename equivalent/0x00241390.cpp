// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 4/4)
// FUN_00241390 @ 0x00241390
typedef unsigned int uint;
struct Environment {
 int room, roomHF; float rolloff, decay, decayHF;
 int reflections; float reflectionsDelay; int reverb; float reverbDelay, diffusion, density, reference;
};
struct SoundState {
 uint unknown0, bufferSize, unknown8; void *buffer; uint used;
 uint list1[2], list2[2]; uint clock, heap, heapSize, heapUsed;
 void *device; char reserved[0x30]; Environment environment;
 float volume, secondaryVolume; uint flags, count; unsigned char enabled; char padding[3]; uint allocationSize;
};
struct Config { uint first, second; };
extern SoundState *DAT_004e5ce0;
extern uint DAT_004e5ce8[4];
extern Environment DAT_004e5cb0;
uint __cdecl FUN_0026fd50(uint, uint);
struct Temporary { char data[64]; void *FUN_002584d0(uint *, uint *, uint, int); void FUN_002580e0(); };
SoundState *__cdecl FUN_00247530(void *);
namespace DSOUND { int __stdcall DirectSoundCreate(void *, void *, void *); }
void __cdecl FUN_002411b0(); void __cdecl FUN_0024c9c0(); void __cdecl FUN_0024c7f0(int);
uint __stdcall FUN_0020c731(uint, uint, uint);
uint __cdecl FUN_00267f80(); void __cdecl FUN_00257dd0(void *);
struct Message { void FUN_0023fe50(const char *); };
bool __cdecl FUN_00241390(Config *config, Message *message) {
 uint size = FUN_0026fd50(config->second, 0x1000) + sizeof(SoundState);
 uint first[2] = {DAT_004e5ce8[0],DAT_004e5ce8[1]};
 uint second[2] = {DAT_004e5ce8[2],DAT_004e5ce8[3]};
 Temporary temp;
 DAT_004e5ce0 = FUN_00247530(temp.FUN_002584d0(second, first, size, 4));
 temp.FUN_002580e0();
 unsigned char *bytes = reinterpret_cast<unsigned char *>(DAT_004e5ce0);
 for (uint i=0;i<sizeof(SoundState);++i) bytes[i]=0;
 DAT_004e5ce0->allocationSize=size;
 DSOUND::DirectSoundCreate(0,&DAT_004e5ce0->device,0);
 FUN_002411b0(); FUN_0024c9c0(); FUN_0024c7f0(1);
 uint value=FUN_0026fd50(config->first,0x1000);
 DAT_004e5ce0->heapSize=value;
 DAT_004e5ce0->heapUsed=0;
 value=FUN_0020c731(0,DAT_004e5ce0->heapSize,0);
 DAT_004e5ce0->heap=value;
 value=FUN_0026fd50(config->second,0x1000);
 DAT_004e5ce0->bufferSize=value;
 SoundState *state=DAT_004e5ce0;
 state->buffer=state->bufferSize ? state+1 : 0;
 DAT_004e5ce0->used=0;
 value=FUN_00267f80();
 DAT_004e5ce0->clock=value;
 FUN_00257dd0(DAT_004e5ce0->list2);
 FUN_00257dd0(DAT_004e5ce0->list1);
 DAT_004e5ce0->volume=1.0f;
 DAT_004e5ce0->secondaryVolume=1.0f;
 DAT_004e5ce0->flags=0; DAT_004e5ce0->count=0; DAT_004e5ce0->enabled=0;
 state=DAT_004e5ce0;
 DAT_004e5cb0.room=-10000; DAT_004e5cb0.roomHF=-10000;
 DAT_004e5cb0.rolloff=0.0f; DAT_004e5cb0.decay=0.1f; DAT_004e5cb0.decayHF=0.1f;
 DAT_004e5cb0.reflections=-10000; DAT_004e5cb0.reflectionsDelay=0.0f;
 DAT_004e5cb0.reverb=-10000; DAT_004e5cb0.reverbDelay=0.0f;
 DAT_004e5cb0.diffusion=0.0f; DAT_004e5cb0.density=0.0f; DAT_004e5cb0.reference=20.0f;
 state->environment=DAT_004e5cb0;
 if(message) message->FUN_0023fe50("Ok");
 return true;
}