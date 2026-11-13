// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 10/10)
// FUN_002656b0 @ 0x002656b0 (src/engine/content/LoadStream.cpp; x64t9). One allocator, two casts: the request ring
// `(HulkLoadEntry*)FUN_0008d6d0(n * sizeof(HulkLoadEntry))` (16-byte entries natively) and the 256-byte buffer
// `(char*)FUN_0008d6d0(256)`. equiv64 typed every FUN_0008d6d0 allocation by the first cast (the buffer's end read
// +128 natively); each allocation now takes its own call site's cast (sitecasts).
#include "compat/ptr.h"
#include "decls/loaders.h"
#include "decls/data/records.h"
extern "C" CoreFiber* __cdecl FUN_0026dbf0();
extern "C" int DAT_004cd504;
extern void* __cdecl FUN_0008d690(unsigned);
namespace fn_fa1126e6 {
struct Config_2656b0 { unsigned first, second, count, value; };
struct Block_2656b0 { unsigned capacity, count, used; char padding[12]; void* slots; void* entries; int sentinel; void FUN_00231550(unsigned, unsigned, unsigned); };
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
extern void __cdecl FUN_00265520();
extern "C" void __cdecl FUN_0026dd70(void*, void (__cdecl*)(), void*, unsigned, unsigned);
struct Object : HulkContentRegistry {
 Object* FUN_002656b0(Config_2656b0* config);
};
Object* Object::FUN_002656b0(Config_2656b0* config) {
 a=0; b=0; c=0; interval=5000; unused=0; first=0; second=0; head=0; tail=0; buffer=0; bufferBegin=0;
 Block_2656b0* p=(Block_2656b0*)FUN_0008d690((unsigned)sizeof(Block_2656b0));
 if(p) { unsigned n=config->first; p->FUN_00231550(n,200,n); }
 first=p;
 p=(Block_2656b0*)FUN_0008d690((unsigned)sizeof(Block_2656b0));
 if(p) { unsigned n=config->second; p->FUN_00231550(n,200,n); }
 second=p;
 unsigned n=config->count;
 // (x64t8) the request ring's entries by their size (8 bytes on the 32-bit builds; each holds a pointer)
 if(n) { unsigned bytes=n*(unsigned)sizeof(HulkLoadEntry); HulkLoadEntry* data=(HulkLoadEntry*)FUN_0008d6d0(bytes); head=data; if(data) { tail=data; begin=data; end=(HulkLoadEntry*)((char*)data+bytes); } else tail=0; }
 else { head=0; tail=0; }
 char* data=(char*)FUN_0008d6d0(256); buffer=data;
 if(data) { bufferBegin=data; bufferCurrent=data; bufferEnd=data+256; } else bufferBegin=0;
 (*(CoreFiber**)&DAT_00527c4c)=FUN_0026dbf0();
 unsigned v=config->value; (*(unsigned*)&DAT_004cd504)=v;
 FUN_0026dd70(&DAT_00527c28,FUN_00265520,this,v,0);
 return this;
}
}
