// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// FUN_00188140 @ 0x00188140
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetTimeBegin_0017fe40();
void __cdecl SetAttachmentIndex_0017fe60();
void __cdecl SetState_0017fe80();
namespace hulkfight { namespace motion { class PropSetStateByIndexTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void v0();
 char fields[12];
 void (__cdecl *callback)();
 char tail[4];
 void FUN_00234960(const char*);
};
template<class T> struct ParamIntConstRange {
 virtual void v0();
 char fields[12];
 void (__cdecl *callback)();
 char tail[4];
 void FUN_002348e0(const char*);
};
}
void __cdecl FUN_002347b0(void*,void**,int);
extern "C" void FUN_00188140() {
 if (DAT_004e14ac == 0) {
 void* params[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack> FloatParam;
 typedef fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack> IntParam;
 FloatParam* a = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(a) { a->FUN_00234960("timeBegin"); new (a) FloatParam; a->callback=SetTimeBegin_0017fe40; }
 params[0]=a;
 IntParam* b=(IntParam*)FUN_0008d690((int)sizeof(IntParam));
 if(b) { b->FUN_002348e0("attachmentIndex"); new (b) IntParam; b->callback=SetAttachmentIndex_0017fe60; }
 params[1]=b;
 IntParam* c=(IntParam*)FUN_0008d690((int)sizeof(IntParam));
 if(c) { c->FUN_002348e0("state"); new (c) IntParam; c->callback=SetState_0017fe80; }
 params[2]=c;
 FUN_002347b0(&DAT_004e14a8,params,3);
 }
 ++DAT_004e14ac;
}
