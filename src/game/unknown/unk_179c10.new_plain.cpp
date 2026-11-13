// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179c10..0x0017afd0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4a73887 {
#define TREE_TU_END }
namespace fn_f4a73887 {} using namespace fn_f4a73887;
#include "game/unknown.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f4a73887 {
extern "C" void* __cdecl FUN_0008d690(unsigned int);
bool SetTimeBegin_0016f930(void*, int); /* (unb5) as defined; address taken only */
char SetOffset_0016f960(void*, void*); /* (unb5) as defined; address taken only */
char SetMinimum_0016f9a0(void*, void*); /* (unb5) as defined; address taken only */
bool SetTraceWidth_0016f9d0(void*, int); /* (unb5) as defined; address taken only */
} // namespace fn_f4a73887
namespace hulkfight { namespace motion {
class TeleportRelativeTrack_17ab80;
} }
namespace fn_f4a73887 {
struct BaseFloat_17ab80 { virtual void slot0(); char pad[12]; void (*callback)(); int tail;  };
struct BaseVector { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234e50(const char*); };
} // namespace fn_f4a73887
namespace fight {
template<class T> struct ParamFloatConstRange_17ab80 : BaseFloat_17ab80 { virtual void slot0(); };
}
namespace fight {
template<class T> struct ParamVector_17ab80 : BaseVector { virtual void slot0(); };
}
namespace fn_f4a73887 {
void __cdecl FUN_002347b0(int*, void**, int);
char SetTimeBegin_0016fa60(void*, int); /* (unb5) as defined; address taken only */
bool SetTimeEnd_0016fa70(void*, int); /* (unb5) as defined; address taken only */
char SetClearOnBegin_0016fa90(void*, char); /* (unb5) as defined; address taken only */
struct FloatBase_17ae00 { virtual void slot0(); char padding[12]; void (*callback)(); int tail;  };
struct BoolBase { virtual void slot0(); char padding[12]; void (*callback)(); int tail;  };
} // namespace fn_f4a73887
namespace hulkfight { namespace motion {
class ChargeClearTrack_17ae00;
} }
namespace fight {
template<class T> struct ParamFloatConstRange_17ae00 : FloatBase_17ae00 { virtual void slot0(); };
}
namespace fight {
template<class T> struct ParamBool_17ae00 : BoolBase { virtual void slot0(); };
}


// 0x0017a180 FUN_0017a180 (213 B): equivalent/0x0017a180.cpp [wrapped: conflict: fight::ParamFloatConstRange; fight::ParamVector]
// sym: ?target@fn_0017a180@@YAXXZ @542174784883 @wd05df3cb3d7a
namespace fn_0017a180 {
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// FUN_0017a180 @ 0x0017a180


void* __cdecl FUN_0008d690(unsigned int);
char FUN_0016f160(void*, int); /* (unb5) as defined; address taken only */ char FUN_0016f170(void*, int); /* (unb5) as defined; address taken only */ char FUN_0016f1a0(void*, void*); /* (unb5) as defined; address taken only */
struct FUN_00234960 { FUN_00234960(const char*); virtual void slot0(); char data[12]; void (__cdecl *callback)(); char tail[4]; };
struct FUN_00234e50 { FUN_00234e50(const char*); virtual void slot0(); char data[12]; void (__cdecl *callback)(); char tail[4]; };
namespace hulkfight { namespace motion { class DriftToHulkTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange : FUN_00234960 { ParamFloatConstRange(const char* s) : FUN_00234960(s) {} virtual void slot0(); };
template<class T> struct ParamVector : FUN_00234e50 { ParamVector(const char* s) : FUN_00234e50(s) {} virtual void slot0(); };
}
void __cdecl FUN_002347b0(void*,void**,int);
void target() {
 if (!DAT_004e133c) {
 void* params[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack> FloatParam;
 typedef fight::ParamVector<hulkfight::motion::DriftToHulkTrack> VectorParam;
 FloatParam* a = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(a) { new(a) FloatParam("timeBegin"); a->callback=(void (*)())FUN_0016f160; } params[0]=a;
 FloatParam* b = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(b) { new(b) FloatParam("timeEnd"); b->callback=(void (*)())FUN_0016f170; } params[1]=b;
 VectorParam* c = (VectorParam*)FUN_0008d690((int)sizeof(VectorParam));
 if(c) { new(c) VectorParam("offset"); c->callback=(void (*)())FUN_0016f1a0; } params[2]=c;
 FUN_002347b0(((unsigned int*)&DAT_004e1338),params,3);
 } ++DAT_004e133c;
}
} // namespace fn_0017a180


// 0x0017a260 FUN_0017a260 (221 B): equivalent/0x0017a260.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamFloatConstRange]
// sym: _FUN_0017a260 @da04e769c8fb @wda975cf2d7c7
namespace fn_0017a260 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0017a260 @ 0x0017a260


extern "C" void* __cdecl FUN_0008d690(unsigned int);
bool SetTimeBegin_0016f1c0(void*, int); /* (unb5) as defined; address taken only */ char SetTimeEnd_0016f1d0(void*, int); /* (unb5) as defined; address taken only */ bool SetMotionState_0016f1f0(void*, void*); /* (unb5) as defined; address taken only */
namespace hulkfight { namespace motion { class MotionStateTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); unsigned int tail; void FUN_00234960(const char*); };
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; const char* values; unsigned int count; void (__cdecl *callback)(); unsigned int tail; void FUN_00234cc0(const char*); };
}
void __cdecl FUN_002347b0(unsigned int*,void**,unsigned int);
extern "C" void __cdecl FUN_0017a260() {
 if ((*(unsigned int*)&DAT_004e1344) == 0) {
 void* params[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack> FloatParam;
 typedef fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack> EnumParam;
 FloatParam* a=(FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(a) { a->FUN_00234960("timeBegin"); new(a) FloatParam; a->callback=(void (*)())SetTimeBegin_0016f1c0; }
 params[0]=a;
 FloatParam* b=(FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(b) { b->FUN_00234960("timeEnd"); new(b) FloatParam; b->callback=(void (*)())SetTimeEnd_0016f1d0; }
 params[1]=b;
 EnumParam* c=(EnumParam*)FUN_0008d690((int)sizeof(EnumParam));
 if(c) { unsigned int count=(*(unsigned int*)&DAT_003f5bb8); c->FUN_00234cc0("motionState"); new(c) EnumParam; c->values="0\\?"; c->count=count; c->callback=(void (*)())SetMotionState_0016f1f0; }
 params[2]=c;
 FUN_002347b0(((unsigned int*)&DAT_004e1340),params,3);
 }
 ++(*(unsigned int*)&DAT_004e1344);
}
} // namespace fn_0017a260


// 0x0017a340 FUN_0017a340 (213 B): equivalent/0x0017a340.cpp [wrapped: conflict: fight::ParamFloatConstRange]
// sym: ?target@fn_0017a340@@YAXXZ @4e4992b34722 @w401fe62ac9d6
namespace fn_0017a340 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0017a340 @ 0x0017a340


bool SetTimeBegin_0016f200(void*, void*); /* (unb5) as defined; address taken only */
char SetTimeEnd_0016f210(void*, int); /* (unb5) as defined; address taken only */
bool SetFinalVelocity_0016f230(void*, int); /* (unb5) as defined; address taken only */
void* __cdecl FUN_0008d690(unsigned int);
namespace hulkfight { namespace motion { class MomentumXZAddTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char padding[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack> Param;
void __cdecl FUN_002347b0(unsigned int*, Param**, int);
void target() {
 if (DAT_004e134c == 0) {
  Param* params[3];
  Param* p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) { p->FUN_00234960("timeBegin"); new (p) Param; p->callback = (void (*)())SetTimeBegin_0016f200; }
  params[0] = p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) { p->FUN_00234960("timeEnd"); new (p) Param; p->callback = (void (*)())SetTimeEnd_0016f210; }
  params[1] = p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) { p->FUN_00234960("finalVelocity"); new (p) Param; p->callback = (void (*)())SetFinalVelocity_0016f230; }
  params[2] = p;
  FUN_002347b0(&DAT_004e1348, params, 3);
 }
 ++DAT_004e134c;
}
} // namespace fn_0017a340

namespace fn_f4a73887 {

// 0x0017ab80 FUN_0017ab80 (256 B): equivalent/0x0017ab80.cpp
// sym: _FUN_0017ab80 @66f5dd58a6c2 @w16dde41c5bb5
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_0017ab80 @ 0x0017ab80
extern "C" void __cdecl FUN_0017ab80() {
 if (DAT_004e1394 == 0) {
 void* params[4];
 typedef fight::ParamFloatConstRange_17ab80<hulkfight::motion::TeleportRelativeTrack_17ab80> F;
 typedef fight::ParamVector_17ab80<hulkfight::motion::TeleportRelativeTrack_17ab80> V;
 F* a = (F*)FUN_0008d690((int)sizeof(F));
 if(a) { ((fight::ParamValueFloat *)(BaseFloat_17ab80 *)a)->FUN_00234960("timeBegin"); new(a) F; a->callback=(void (*)())SetTimeBegin_0016f930; } params[0]=a;
 V* b = (V*)FUN_0008d690((int)sizeof(V));
 if(b) { b->FUN_00234e50("offset"); new(b) V; b->callback=(void (*)())SetOffset_0016f960; } params[1]=b;
 V* c = (V*)FUN_0008d690((int)sizeof(V));
 if(c) { c->FUN_00234e50("minimum"); new(c) V; c->callback=(void (*)())SetMinimum_0016f9a0; } params[2]=c;
 F* d = (F*)FUN_0008d690((int)sizeof(F));
 if(d) { ((fight::ParamValueFloat *)(BaseFloat_17ab80 *)d)->FUN_00234960("traceWidth"); new(d) F; d->callback=(void (*)())SetTraceWidth_0016f9d0; } params[3]=d;
 FUN_002347b0(&DAT_004e1390, params, 4);
 }
 ++DAT_004e1394;
}

} // namespace fn_f4a73887

// 0x0017ad20 FUN_0017ad20 (213 B): equivalent/0x0017ad20.cpp [wrapped: conflict: fight::ParamFloatConstRange; fight::ParamString; fight::ParamVector]
// sym: _FUN_0017ad20 @098b49be57b0 @w8f911d2031de
namespace fn_0017ad20 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0017ad20 @ 0x0017ad20


extern "C" void* __cdecl FUN_0008d690(unsigned int);
bool SetTimeBegin_0016fa00(void*, int); /* (unb5) as defined; address taken only */ bool SetText_00170de0(void*, void*); /* (unb5) as defined; address taken only */ bool SetOffset_0016fa40(void*, void*); /* (unb5) as defined; address taken only */
namespace hulkfight { namespace motion { class TeleportToLocatorTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234960(const char*); };
template<class T> struct ParamString { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_002349e0(const char*); };
template<class T> struct ParamVector { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234e50(const char*); };
}
 
void __cdecl FUN_002347b0(void*, void**, int);
extern "C" void FUN_0017ad20() {
 if (!DAT_004e13a4) {
 void* params[3]; typedef hulkfight::motion::TeleportToLocatorTrack Track;
 fight::ParamFloatConstRange<Track>* a = (fight::ParamFloatConstRange<Track>*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<Track>));
 if(a) { a->FUN_00234960("timeBegin"); new(a) fight::ParamFloatConstRange<Track>; a->callback=(void (*)())SetTimeBegin_0016fa00; } params[0]=a;
 fight::ParamString<Track>* b = (fight::ParamString<Track>*)FUN_0008d690((int)sizeof(fight::ParamString<Track>));
 if(b) { b->FUN_002349e0("text"); new(b) fight::ParamString<Track>; b->callback=(void (*)())SetText_00170de0; } params[1]=b;
 fight::ParamVector<Track>* c = (fight::ParamVector<Track>*)FUN_0008d690((int)sizeof(fight::ParamVector<Track>));
 if(c) { c->FUN_00234e50("offset"); new(c) fight::ParamVector<Track>; c->callback=(void (*)())SetOffset_0016fa40; } params[2]=c;
 FUN_002347b0(&DAT_004e13a0,params,3);
 }
 ++DAT_004e13a4;
}
} // namespace fn_0017ad20

namespace fn_f4a73887 {

// 0x0017ae00 FUN_0017ae00 (213 B): equivalent/0x0017ae00.cpp
// sym: ?target@fn_f4a73887@@YAXXZ @643d32500e54 @wf745f7f3cbc0
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_0017ae00 @ 0x0017ae00
void __cdecl target() {
 if (!DAT_004e13ac) {
 void* params[3];
 typedef fight::ParamFloatConstRange_17ae00<hulkfight::motion::ChargeClearTrack_17ae00> FloatParam;
 typedef fight::ParamBool_17ae00<hulkfight::motion::ChargeClearTrack_17ae00> BoolParam;
 FloatParam* a = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(a) { ((fight::ParamValueFloat *)(FloatBase_17ae00 *)a)->FUN_00234960("timeBegin"); a = new(a) FloatParam; a->callback = (void (*)())SetTimeBegin_0016fa60; }
 params[0] = a;
 FloatParam* b = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(b) { ((fight::ParamValueFloat *)(FloatBase_17ae00 *)b)->FUN_00234960("timeEnd"); b = new(b) FloatParam; b->callback = (void (*)())SetTimeEnd_0016fa70; }
 params[1] = b;
 BoolParam* c = (BoolParam*)FUN_0008d690((int)sizeof(BoolParam));
 if(c) { ((fight::ParamValueBool *)(BoolBase *)c)->FUN_00234860("clearOnBegin"); c = new(c) BoolParam; c->callback = (void (*)())SetClearOnBegin_0016fa90; }
 params[2] = c;
 FUN_002347b0(&DAT_004e13a8,params,3);
 }
 ++DAT_004e13ac;
}

} // namespace fn_f4a73887
