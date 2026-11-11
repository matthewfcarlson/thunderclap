// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f2e40..0x001f6bc0 (kind game, layer game, confidence high), dominant class CSoundVoiceManager
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#define TREE_TU_BEGIN namespace fn_f6ac3dc9 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6ac3dc9 {} using namespace fn_f6ac3dc9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6ac3dc9 {
struct Vec_1f64c0 { float x,y,z; };
struct Transform_1f64c0 { char pad[0x30]; Vec_1f64c0 a,b,c; };
extern "C" void __cdecl FUN_0024ca70(Vec_1f64c0*);
extern "C" void __cdecl FUN_0024cab0(Vec_1f64c0*,Vec_1f64c0*);
struct Child_1f64c0 { void FUN_001f5860(unsigned); };
struct Object {
 char pad0[8]; Child_1f64c0* children[32]; int count;
 char pad1[0x328-0x8c]; Transform_1f64c0* transform;
 int pad2; int state;
 void FUN_001f4140(int);
 void FUN_001f5c20(unsigned);
 void FUN_001f63a0();
 void FUN_001f64c0(unsigned arg, char enabled);
};
struct Item_1f6580 { char pad[4]; void* handle; void FUN_001f5860(float step); };
extern "C" void __cdecl FUN_00247890(void*, float);
struct State_1f6580 { char pad0[8]; Item_1f6580* items[32]; int count; char pad1[0x32c-0x8c]; unsigned int nesting; char pad2[4]; float value; void FUN_001f4610(int,int,int); void FUN_001f4140(int); void target(); };
struct Voice_1f6650 {
    int pad0;
    void* handle;
};
class Channel {
public:
    void FUN_001f5860(float dt);
};
class Mixer {
public:
    char pad0[8];
    Voice_1f6650* items[32];
    int count;
    Voice_1f6650* ref8c;
    char pad90[0xc0 - 0x90];
    Voice_1f6650* refc0;
    Voice_1f6650* refc4;
    Voice_1f6650* refc8;
    char padcc[0x32c - 0xcc];
    int countdown;
    int pad330;
    float gain;
    void FUN_001f46a0();
    void FUN_001f4140(int a);
    void FUN_001f6650();
};


// 0x001f64c0 FUN_001f64c0 (183 B): matches/0x001f64c0.cpp
// sym: ?FUN_001f64c0@Object@fn_f6ac3dc9@@QAEXID@Z
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 10/10)
// FUN_001f64c0 @ 0x001f64c0
void Object::FUN_001f64c0(unsigned arg, char enabled) {
 char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
 if (enabled && state == 0) {
  if (transform) {
   FUN_0024ca70(&transform->a);
   FUN_0024cab0(&transform->b, &transform->c);
  }
  FUN_001f4140(1);
  FUN_001f5c20(arg);
  FUN_001f63a0();
 } else {
  FUN_001f4140(0);
  for (int i=0; i<count; ++i) children[i]->FUN_001f5860(arg);
 }
}


// 0x001f6580 FUN_001f6580 (193 B): equivalent/0x001f6580.cpp
// sym: ?target@State_1f6580@fn_f6ac3dc9@@QAEXXZ @7c6a6a573db1 @w803054ca7cc3
// STATUS: equivalent (tools/equiv.py level 3: 19650 inputs, branch coverage 14/14)
// FUN_001f6580 @ 0x001f6580
void State_1f6580::target() { char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */ ++nesting; if(nesting == 1) { FUN_001f4610(1,1,1); value=0; for(int i=0;i<count;++i) { void* h=items[i]->handle; if(h) FUN_00247890(h,value); } for(int j=0;j<100;++j) { FUN_001f4140(0); for(int i=0;i<count;++i) items[i]->FUN_001f5860(0.01666666753590107f); FUN_00240bb0(); } }  }


// 0x001f6650 FUN_001f6650 (367 B): equivalent/0x001f6650.cpp
// sym: ?FUN_001f6650@Mixer@fn_f6ac3dc9@@QAEXXZ @52e2c8bc9038 @w6689b86f9f46
// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 30/30)
// FUN_001f6650 @ 0x001f6650
void Mixer::FUN_001f6650()
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    if (--countdown == 0) {
        FUN_001f46a0();
        countdown = 0;
        gain = 1.0f;
        for (int i = 0; i < count; i++) {
            Voice_1f6650* v = items[i];
            float base;
            if (v == ref8c)
                base = DAT_004c7df4;
            else if (v == refc8 || v == refc4)
                base = DAT_004c7df8;
            else if (v == refc0)
                base = DAT_004c7df0;
            else
                base = DAT_004c7df8;
            if (v->handle != 0)
                FUN_00247890(v->handle, base * 0.01f * gain);
        }
        FUN_001f4140(0);
        for (int j = 0; j < count; j++)
            ((Channel*)items[j])->FUN_001f5860(0.016666668f);
        FUN_001f4140(0);
        for (int k = 0; k < count; k++)
            ((Channel*)items[k])->FUN_001f5860(0.016666668f);
        FUN_00240bb0();
    }
}

} // namespace fn_f6ac3dc9
