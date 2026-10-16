// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00334540 @ 0x00334540
#include "decls/data/engine/core.h"

typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
void __cdecl FUN_002705f0();
void* __cdecl FUN_00263ea0(unsigned int);
struct Resource_334540 { virtual void slot0(); Resource_334540* FUN_0028edb0(); };
namespace core {
struct Object { virtual void slot0(); int id; };
struct RefCount : Object { int count; };
}
namespace movie {
struct RenderStrategy { virtual void slot0(); };
struct RenderStrategyBink : RenderStrategy, core::Object {
 int count; Resource_334540* resource; int f14,f18,f1c,f20; float f24,f28; int f2c,f30; int f34,f38,f3c,f40,f44; unsigned char f48;
 RenderStrategyBink* FUN_00334540();
};
}
movie::RenderStrategyBink* movie::RenderStrategyBink::FUN_00334540() {
 new(static_cast<RenderStrategy*>(this)) RenderStrategy;
 new(static_cast<core::Object*>(this)) core::Object;
 id=DAT_004cdbb0;
 FUN_002705f0();
 new(static_cast<core::Object*>(this)) core::RefCount;
 count=0;
 FUN_002705f0();
 new(this) RenderStrategyBink;
 resource=0; f14=0; f18=0; f1c=0; f20=0; f2c=0; f30=0; f48=0;
 f24=1.0f; f28=1.0f;
 f34=0; f38=0; f3c=0; f40=0; f44=0;
 Resource_334540* p=(Resource_334540*)FUN_00263ea0(32);
 if(p) p=p->FUN_0028edb0();
 resource=p;
 p->slot0();
 return this;
}