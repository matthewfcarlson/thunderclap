// STATUS: equivalent (tools/equiv.py level 3: 2976 inputs, branch coverage 2/2)
// DataHandlerRawLoader::vfunc_5 @ 0x001fb050
#include "decls/address.h"
inline void* __cdecl operator new(unsigned, void* p) { return p; }
struct StreamBackend { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Stream { char pad[0x284]; StreamBackend* backend; void FUN_00266c40(); };
struct Counter_1fb050 { char pad[0x30]; unsigned count; };
struct CDataHandlerObject { virtual void vfunc_0(); unsigned refs; unsigned size; void* data; };
extern unsigned DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned);
extern int __cdecl FUN_00266da0(int);
extern void* __cdecl FUN_0008d6d0(unsigned);
extern void* __cdecl FUN_00263ea0(unsigned);
extern int __cdecl FUN_000964a0(char*, unsigned, const char*, ...);
struct DataHandlerRawLoader { char pad[0x14]; Counter_1fb050* counter; void vfunc_5(CDataHandlerObject**, unsigned __int64*, Stream*, unsigned); };
void DataHandlerRawLoader::vfunc_5(CDataHandlerObject** out, unsigned __int64* id, Stream* stream, unsigned unused) {
 unsigned cookie=DAT_004d9968;
 int old = FUN_00266da0(1);
 unsigned size;
 stream->backend->FUN_002647e0(&size,1,4,1);
 stream->FUN_00266c40();
 void* data = FUN_0008d6d0(size);
 stream->backend->FUN_002647e0(data,size,1,1);
 CDataHandlerObject* obj = (CDataHandlerObject*)FUN_00263ea0(16);
 if(obj) { new (obj) CDataHandlerObject; obj->refs=0; obj->size=size; obj->data=data; }
 char name[64]; unsigned n=counter->count++;
 FUN_000964a0(name,64,"GameDataHandlerRaw%d",n);
 *out=obj;
 *id=FUN_002672f0(name,0,0);
 FUN_00266da0(old);
 __security_check_cookie(cookie);
}