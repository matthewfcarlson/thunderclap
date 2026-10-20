// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000f83f0 @ 0x000f83f0
#include "compat/ptr.h"
struct RateProvider { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7(); };
struct Context { char pad0[12]; void** entries; int maxIndex; char pad14[16]; RateProvider* providers[58]; int version; };
struct Frame_f83f0 { float unused0, unused1, scale, unused3; };
struct Parameters_f83f0 { Frame_f83f0 frames[8]; char pad80[8]; int frameIndex; };
void __cdecl FUN_0008d340(void*);
unsigned int __cdecl FUN_00294b80(void*);
void* __cdecl FUN_0008d6d0(hulk_uintptr);
void __cdecl FUN_000fb830(void*, unsigned int, void*, float, RateProvider*);
struct Object { int providerIndex; char pad4[8]; void* cache; void* source; int sourceIndex; unsigned char enabled; char pad19[3]; float value; int version; void* target(Context*, Parameters_f83f0*); };
void* Object::target(Context* context, Parameters_f83f0* parameters) {
 void* input = source;
 if (!input) {
  if (sourceIndex < 0 || sourceIndex > context->maxIndex) return 0;
  input = context->entries[sourceIndex];
  if (!input) return 0;
 }
 if (!enabled) return input;
 int currentVersion = context->version;
 if (version != -1 && version == currentVersion) return cache;
 float rate = context->providers[0]->slot7();
 float factor = value / ((14.0f / rate) * parameters->frames[parameters->frameIndex].scale);
 if (cache) { FUN_0008d340(cache); cache = 0; }
 unsigned int length = FUN_00294b80(input);
 unsigned int size = (length + 5 - (int)((double)length * -0.2f)) * 2;
 cache = FUN_0008d6d0(size);
 if (!cache) return 0;
 FUN_000fb830(cache, size, input, factor, context->providers[providerIndex]);
 version = currentVersion;
 return cache;
}