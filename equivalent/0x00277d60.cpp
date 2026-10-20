// STATUS: equivalent (tools/equiv.py level 3: 526 inputs, branch coverage 38/40, incomplete; run with --inputs 12000)
// FUN_00277d60 @ 0x00277d60
#include "compat/ptr.h"
typedef unsigned int U_277d60;
extern hulk_uintptr __cdecl FUN_0026fd80(hulk_uintptr,U_277d60);
extern hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr,U_277d60);
extern void __cdecl FUN_00279d30(void*,U_277d60,void*,U_277d60,U_277d60);
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
struct Reader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual int read(U_277d60,U_277d60,U_277d60,void*,void*,U_277d60,U_277d60*,U_277d60); };
struct State_277d60 { U_277d60 unknown; char* source; U_277d60 total; U_277d60 size; U_277d60 position; U_277d60 skip; U_277d60 sourceSize; U_277d60 unused; U_277d60 alignment; char* buffer; U_277d60 capacity;
int target(Reader* reader,U_277d60 a2,U_277d60 a3,U_277d60 a4,U_277d60 start,char* dest,U_277d60 requested,U_277d60* result,U_277d60 a9);
};
int State_277d60::target(Reader* reader,U_277d60 a2,U_277d60 a3,U_277d60 a4,U_277d60 start,char* dest,U_277d60 requested,U_277d60* result,U_277d60 a9) {
 if(start>size) { *result=requested; return 1; }
 U_277d60 count=requested;
 if(start+requested>size) count=size-start;
 U_277d60 done=total, pos=position, offset=skip, carry=0;
 while(count) {
 hulk_uintptr aligned=FUN_0026fd80(pos,alignment);
 hulk_uintptr room=capacity;
 hulk_uintptr available=sourceSize-aligned;
 if(offset) room-=FUN_0026fd50(offset,alignment);
 if(available<room) room=available;
 hulk_uintptr amount=FUN_0026fd50(room-carry,alignment);
 U_277d60 readResult;
 int status=reader->read(a2,a3,a4,source+aligned+carry,buffer+carry,amount,&readResult,1);
 if(status!=1) return status;
 char* block=buffer-aligned+pos;
 char* end=buffer+room;
 while(count) {
 if(block+4>=end) break;
 U_277d60 packed=*(unsigned short*)block;
 U_277d60 expanded=*(unsigned short*)(block+2);
 U_277d60 length=packed?packed:expanded;
 if(block+4+length>end) break;
 U_277d60 remaining=expanded-offset;
 U_277d60 n=remaining;
 if(n>count) n=count;
 char* temp=offset?end:dest;
 if(!packed) memcpy(temp,block+4,n+offset);
 else FUN_00279d30(block+4,packed,temp,n+offset,expanded);
 if(offset) memcpy(dest,temp+offset,n);
 if(n!=remaining) offset=n;
 else { offset=0; pos+=length+4; block+=length+4; }
 done+=n; dest+=n; count-=n;
 }
 if(count && block!=end) {
 carry=FUN_0026fd50((U_277d60)(end-block),alignment);
 memcpy(buffer,end-carry,carry);
 } else carry=0;
 }
 total=done; position=pos; skip=offset; *result=requested; return 1;
}
