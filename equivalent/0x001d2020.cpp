// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001d2020 @ 0x001d2020
struct LuaState;
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl FUN_00212d70(LuaState*);
extern "C" void __cdecl FUN_002135a0(LuaState*,int,const char*);
extern "C" void __cdecl FUN_00212ed0(LuaState*,int);
extern "C" void __cdecl FUN_002139a0(LuaState*,int,int);
extern "C" const char* __cdecl FUN_00213190(LuaState*,int);
extern "C" void __cdecl FUN_00212d80(LuaState*,int);
extern "C" void __cdecl FUN_002133d0(LuaState*,const char*);
extern "C" void __cdecl FUN_00213c40(LuaState*);
extern "C" int __cdecl FUN_00267760(char*,int,const char*,...);
extern "C" void __cdecl FUN_00212de0(LuaState*,int);
extern "C" int __cdecl FUN_001d0c60(LuaState*,const char*);
extern "C" void __cdecl FUN_00212e20(LuaState*,int);
int __cdecl FUN_001d2020(LuaState* state) {
 unsigned int cookie=DAT_004d9968;
 char name[64];
 int result=-1;
 if(FUN_00212d70(state)>=1) {
 FUN_002135a0(state,-10001,"tostring");
 FUN_00212ed0(state,1);
 FUN_002139a0(state,1,1);
 const char* text=FUN_00213190(state,-1);
 if(!text){
 FUN_00212d80(state,-2);
 FUN_002133d0(state,"'LuaDebugChannel':  invalid channel name.");
 FUN_00213c40(state);
 } else {
 FUN_00267760(name,64,"%s",text);
 FUN_00212d80(state,-2);
 FUN_00212de0(state,1);
 result=FUN_001d0c60(state,name);
 FUN_002133d0(state,name);
 FUN_00212e20(state,1);
 }
 }
 __security_check_cookie(cookie);
 return result;
}