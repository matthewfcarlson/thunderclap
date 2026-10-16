// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// FUN_0017a180 @ 0x0017a180
#include "decls/data/game/hulkfight/motion.h"

inline void* __cdecl operator new(unsigned int,void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0016f160(); void __cdecl FUN_0016f170(); void __cdecl FUN_0016f1a0();
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
 FloatParam* a = (FloatParam*)FUN_0008d690(24);
 if(a) { new(a) FloatParam("timeBegin"); a->callback=FUN_0016f160; } params[0]=a;
 FloatParam* b = (FloatParam*)FUN_0008d690(24);
 if(b) { new(b) FloatParam("timeEnd"); b->callback=FUN_0016f170; } params[1]=b;
 VectorParam* c = (VectorParam*)FUN_0008d690(24);
 if(c) { new(c) VectorParam("offset"); c->callback=FUN_0016f1a0; } params[2]=c;
 FUN_002347b0(((unsigned int*)&DAT_004e1338),params,3);
 } ++DAT_004e133c;
}
