// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 23/26, incomplete)
// FUN_001d36f0 @ 0x001d36f0
// cl-flags: /GS
#include "decls/data/lua.h"
struct Stream { virtual void s0(); virtual void release(); virtual void s2(); virtual void read(char*,int,int); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual int size(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void reset(); virtual void s22(); virtual bool valid(); };
extern void __cdecl thunk_FUN_002710d0(Stream**,void*,int,int,int,int,int,int);
extern char* __cdecl FUN_0008d6d0(int);
extern void __cdecl FUN_0008d340(void*);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00339a60(LuaVMState* L, const char* buff, unsigned int size, const char* name);
extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213ba0(LuaVMState* L, int what, int data);
unsigned char __stdcall FUN_001d1080(const char* name, LuaVMState* L);
const char* __stdcall FUN_001d10e0(const char* name, LuaVMState* L);
struct Handler_1d36f0 { int unused; int state; LuaVMState* lua; int FUN_001d2810(LuaVMState*,const char*,int,const char*); int run(void*,int); };
int Handler_1d36f0::run(void* name,int unusedArg) {
 Stream* stream; thunk_FUN_002710d0(&stream,name,0,0,1,0,1,1);
 stream->reset();
 if (!stream->valid()) {stream->release();  return 0;}
 int length=stream->size(); if (!length) {stream->release();  return 0;}
 char* buffer=FUN_0008d6d0(length+1);
 stream->read(buffer,length,1); stream->reset(); buffer[length]=0; stream->release();
 state=FUN_001d2810(lua,buffer,length,(const char*)name)?0:3;
 char script[]="__RESUME_RC__, __RESUME_ERR__ = coroutine.resume( __THE_SCENARIO_COROUTINE__ )";
 int n=0; while(script[n]) ++n;
 LuaVMState* L=lua; int top=FUN_00212d70(L);
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