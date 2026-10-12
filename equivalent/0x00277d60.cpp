// STATUS: equivalent (tools/equiv.py level 3: 526 inputs, branch coverage 38/40, incomplete; run with --inputs 12000)
// FUN_00277d60 @ 0x00277d60
typedef unsigned int U;
extern U __cdecl FUN_0026fd80(U,U);
extern U __cdecl FUN_0026fd50(U,U);
extern void __cdecl FUN_00279d30(void*,U,void*,U,U);
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
struct Reader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual int read(U,U,U,void*,void*,U,U*,U); };
struct State { U unknown; char* source; U total; U size; U position; U skip; U sourceSize; U unused; U alignment; char* buffer; U capacity;
int target(Reader* reader,U a2,U a3,U a4,U start,char* dest,U requested,U* result,U a9);
};
int State::target(Reader* reader,U a2,U a3,U a4,U start,char* dest,U requested,U* result,U a9) {
 if(start>size) { *result=requested; return 1; }
 U count=requested;
 if(start+requested>size) count=size-start;
 U done=total, pos=position, offset=skip, carry=0;
 while(count) {
 U aligned=FUN_0026fd80(pos,alignment);
 U room=capacity;
 U available=sourceSize-aligned;
 if(offset) room-=FUN_0026fd50(offset,alignment);
 if(available<room) room=available;
 U amount=FUN_0026fd50(room-carry,alignment);
 U readResult;
 int status=reader->read(a2,a3,a4,source+aligned+carry,buffer+carry,amount,&readResult,1);
 if(status!=1) return status;
 char* block=buffer-aligned+pos;
 char* end=buffer+room;
 while(count) {
 if(block+4>=end) break;
 U packed=*(unsigned short*)block;
 U expanded=*(unsigned short*)(block+2);
 U length=packed?packed:expanded;
 if(block+4+length>end) break;
 U remaining=expanded-offset;
 U n=remaining;
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
 carry=FUN_0026fd50((U)(end-block),alignment);
 memcpy(buffer,end-carry,carry);
 } else carry=0;
 }
 total=done; position=pos; skip=offset; *result=requested; return 1;
}
