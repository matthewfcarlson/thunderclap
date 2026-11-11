// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fa9c0..0x001fb3f0 (kind game, layer game, confidence high), dominant class MyFileStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f57d431a {
#define TREE_TU_END }
namespace fn_f57d431a {} using namespace fn_f57d431a;
#include "game/global.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f57d431a {
struct StreamBackend {  };
struct Stream_1fb050 { char pad[0x284]; StreamBackend* backend; void FUN_00266c40(); };
struct Counter_1fb050 { char pad[0x30]; unsigned count; };
struct CDataHandlerObject_1fb050 { virtual void vfunc_0(); unsigned refs; unsigned size; void* data; };
extern "C" int __cdecl FUN_00266da0(int);
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
extern void* __cdecl FUN_00263ea0(unsigned);
extern int __cdecl FUN_000964a0(char*, unsigned, const char*, ...);

} // namespace fn_f57d431a

// 0x001fb050 DataHandlerRawLoader::vfunc_5 (221 B): equivalent/0x001fb050.cpp
// sym: ?vfunc_5@DataHandlerRawLoader@@UAEXPAX00H@Z @626543548415 @w84302fac356d
// STATUS: equivalent (tools/equiv.py level 3: 16785 inputs, branch coverage 2/2)
// DataHandlerRawLoader::vfunc_5 @ 0x001fb050
void DataHandlerRawLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { CDataHandlerObject_1fb050 ** out = (CDataHandlerObject_1fb050 **)__p0; unsigned long long * id = (unsigned long long *)__p1; Stream_1fb050 * stream = (Stream_1fb050 *)__p2; unsigned int unused = (unsigned int)__p3;

 int old = FUN_00266da0(1);
 unsigned size;
 ((owners::X_2647e0 *)(stream->backend))->FUN_002647e0((hulk_intptr)(&size), (hulk_intptr)1, 4, (hulk_intptr)1);
 stream->FUN_00266c40();
 void* data = FUN_0008d6d0(size);
 ((owners::X_2647e0 *)(stream->backend))->FUN_002647e0((hulk_intptr)data, (hulk_intptr)size, 1, (hulk_intptr)1);
 CDataHandlerObject_1fb050* obj = (CDataHandlerObject_1fb050*)FUN_00263ea0(16);
 if(obj) { new (obj) CDataHandlerObject_1fb050; obj->refs=0; obj->size=size; obj->data=data; }
 char name[64]; unsigned n=(*(Counter_1fb050 * *)&this->f_14)->count++;
 FUN_000964a0(name,64,"GameDataHandlerRaw%d",n);
 *out=obj;
 *id=FUN_002672f0(name,0,0);
 FUN_00266da0(old);
}

