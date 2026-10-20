// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_002656b0 @ 0x002656b0
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/content.h"

struct Config_2656b0 { unsigned first, second, count, value; };
struct Block_2656b0 { void FUN_00231550(unsigned, unsigned, unsigned); };
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern void* __cdecl FUN_0008d6d0(hulk_uintptr);
extern unsigned __cdecl FUN_0026dbf0();
extern void __cdecl FUN_00265520();
extern void __cdecl FUN_0026dd70(void*, void (__cdecl*)(), void*, unsigned, unsigned);
struct Object {
 unsigned char a,b,c,pad;
 unsigned interval, unused;
 Block_2656b0 *first,*second;
 char *storage,*begin,*current,*end;
 unsigned reserved;
 char *buffer,*bufferBegin,*bufferCurrent,*bufferEnd;
 Object* FUN_002656b0(Config_2656b0* config);
};
Object* Object::FUN_002656b0(Config_2656b0* config) {
 a=0; b=0; c=0; interval=5000; unused=0; first=0; second=0; storage=0; begin=0; buffer=0; bufferBegin=0;
 Block_2656b0* p=(Block_2656b0*)FUN_0008d690(36);
 if(p) { unsigned n=config->first; p->FUN_00231550(n,200,n); }
 first=p;
 p=(Block_2656b0*)FUN_0008d690(36);
 if(p) { unsigned n=config->second; p->FUN_00231550(n,200,n); }
 second=p;
 unsigned n=config->count;
 if(n) { unsigned bytes=n*8; char* data=(char*)FUN_0008d6d0(bytes); storage=data; if(data) { begin=data; current=data; end=data+bytes; } else begin=0; }
 else { storage=0; begin=0; }
 char* data=(char*)FUN_0008d6d0(256); buffer=data;
 if(data) { bufferBegin=data; bufferCurrent=data; bufferEnd=data+256; } else bufferBegin=0;
 DAT_00527c4c=FUN_0026dbf0();
 unsigned v=config->value; (*(unsigned*)&DAT_004cd504)=v;
 FUN_0026dd70(((char*)((char*)&DAT_0051de40 + 40424)),FUN_00265520,this,v,0);
 return this;
}