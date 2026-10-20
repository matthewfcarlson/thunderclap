// STATUS: equivalent (tools/equiv.py level 3: 9310 inputs, branch coverage 23/26, incomplete)
// FUN_001d36f0 @ 0x001d36f0
// cl-flags: /GS
#include "compat/ptr.h"
struct Stream { virtual void s0(); virtual void release(); virtual void s2(); virtual void read(char*,int,int); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual int size(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void reset(); virtual void s22(); virtual bool valid(); };
extern void __cdecl thunk_FUN_002710d0(Stream**,void*,int,int,int,int,int,int);
extern char* __cdecl FUN_0008d6d0(hulk_intptr);
extern void __cdecl FUN_0008d340(void*);
extern int __cdecl FUN_00212d70(void*);
extern int __cdecl FUN_00339a60(void*,const char*,int,const char*);
extern int __cdecl FUN_002139f0(void*,int,int,int);
extern void __cdecl FUN_00212d80(void*,int);
extern void __cdecl FUN_00213380(void*,const char*,int);
extern void __cdecl FUN_00213600(void*,int);
extern void __cdecl FUN_002133d0(void*,const char*);
extern const char* __cdecl FUN_00213190(void*,int);
extern void __cdecl FUN_00213ba0(void*,int,int);
struct Handler_1d36f0 { int unused; int state; void* lua; int FUN_001d2810(void*,char*,int,void*); bool FUN_001d1080(const char*,void*); void FUN_001d10e0(const char*,void*); int run(void*,int); };
int Handler_1d36f0::run(void* name,int unusedArg) {
 Stream* stream; thunk_FUN_002710d0(&stream,name,0,0,1,0,1,1);
 stream->reset();
 if (!stream->valid()) {stream->release();  return 0;}
 int length=stream->size(); if (!length) {stream->release();  return 0;}
 char* buffer=FUN_0008d6d0(length+1);
 stream->read(buffer,length,1); stream->reset(); buffer[length]=0; stream->release();
 state=FUN_001d2810(lua,buffer,length,name)?0:3;
 char script[]="__RESUME_RC__, __RESUME_ERR__ = coroutine.resume( __THE_SCENARIO_COROUTINE__ )";
 int n=0; while(script[n]) ++n;
 void* L=lua; int top=FUN_00212d70(L);
 int result=FUN_00339a60(L,script,n,"=ScriptHandler::DoLuaBuffer");
 if (!result) result=FUN_002139f0(L,0,-1,0);
 if(result) FUN_00212d80(L,top);
 state=result?0:3;
 if(FUN_001d1080("__RESUME_RC__",lua)) {
 FUN_00213380(lua,"coroutine",9); FUN_00213600(lua,-10001); FUN_002133d0(lua,"status"); FUN_00213600(lua,-2); FUN_00213380(lua,"__THE_SCENARIO_COROUTINE__",26); FUN_00213600(lua,-10001); FUN_002139f0(lua,1,1,0);
 const char* status=FUN_00213190(lua,-1); FUN_00212d80(lua,-3);
 const char* dead="dead"; int i=0; while(i<5 && status[i]==dead[i]) ++i;
 if(i!=5 && state==3) state=4;
 } else FUN_001d10e0("__RESUME_ERR__",lua);
 FUN_00213ba0(lua,2,0); FUN_0008d340(buffer); int answer=state;  return answer;
}