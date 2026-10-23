// STATUS: equivalent (tools/equiv.py level 3: 16785 inputs, branch coverage 2/2)
// DataHandlerRawLoader::vfunc_5 @ 0x001fb050
// cl-flags: /GS
#include "gen/global.h"

#include "decls/address.h"
inline void* __cdecl operator new(unsigned, void* p) { return p; }
struct StreamBackend { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Stream_1fb050 { char pad[0x284]; StreamBackend* backend; void FUN_00266c40(); };
struct Counter_1fb050 { char pad[0x30]; unsigned count; };
struct CDataHandlerObject_1fb050 { virtual void vfunc_0(); unsigned refs; unsigned size; void* data; };
extern int __cdecl FUN_00266da0(int);
extern void* __cdecl FUN_0008d6d0(unsigned);
extern void* __cdecl FUN_00263ea0(unsigned);
extern int __cdecl FUN_000964a0(char*, unsigned, const char*, ...);

void DataHandlerRawLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int __p3) { CDataHandlerObject_1fb050 ** out = (CDataHandlerObject_1fb050 **)__p0; unsigned long long * id = (unsigned long long *)__p1; Stream_1fb050 * stream = (Stream_1fb050 *)__p2; unsigned int unused = (unsigned int)__p3;

 int old = FUN_00266da0(1);
 unsigned size;
 stream->backend->FUN_002647e0(&size,1,4,1);
 stream->FUN_00266c40();
 void* data = FUN_0008d6d0(size);
 stream->backend->FUN_002647e0(data,size,1,1);
 CDataHandlerObject_1fb050* obj = (CDataHandlerObject_1fb050*)FUN_00263ea0(16);
 if(obj) { new (obj) CDataHandlerObject_1fb050; obj->refs=0; obj->size=size; obj->data=data; }
 char name[64]; unsigned n=(*(Counter_1fb050 * *)&this->f_14)->count++;
 FUN_000964a0(name,64,"GameDataHandlerRaw%d",n);
 *out=obj;
 *id=FUN_002672f0(name,0,0);
 FUN_00266da0(old);
}
