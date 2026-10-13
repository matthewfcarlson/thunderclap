// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::scenario::LuaAction::vfunc_5 @ 0x001a1700
struct TypeInfo { unsigned int data; }; extern TypeInfo DAT_00494b44, DAT_00494b60, DAT_004c13d0;
struct Object { char pad[8]; unsigned int id; };
extern Object* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
extern unsigned int __cdecl FUN_001d0440();
extern void* __cdecl FUN_001d0430(unsigned int);
struct Context { void FUN_001d2ee0(Object*); void FUN_001d1cb0(); void FUN_001d1d50(const char*,const char*); void FUN_001d1d30(); bool FUN_001d29b0(void*,bool*); };
extern Context* __cdecl FUN_001d4c90();
struct Handle { void FUN_001cb170(); };
namespace hulkfight { namespace scenario {
struct LuaAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int, int); char pad[28]; void* object; void* script; Handle handle; };
bool LuaAction::vfunc_5(int n,int unused) { if(n>0) return true; if(!script) return false; Context* ctx=FUN_001d4c90(); if(!ctx) return false; Object* o=FUN_00344e74(object,0,&DAT_00494b44,&DAT_004c13d0,0); if(o) { unsigned int id=o->id; if(FUN_001d0440()!=id) { FUN_001d0430(o->id); handle.FUN_001cb170(); } } else { o=FUN_00344e74(object,0,&DAT_00494b44,&DAT_00494b60,0); if(o) ctx->FUN_001d2ee0(o); } ctx->FUN_001d1cb0(); ctx->FUN_001d1d50("node","DO NOT USE THIS IN RELEASE MODE!  Talk to Kevin..."); ctx->FUN_001d1d30(); bool result=false; if(!ctx->FUN_001d29b0(script,&result)) script=0; return script!=0; }
}}
