// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00053ef0 @ 0x00053ef0
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void FUN_00049ed0();
extern "C" void FUN_00047fc0();
extern "C" void FUN_00047fd0();
extern int DAT_00427754;
extern int DAT_004dc504;
extern int DAT_004dc500;
struct FUN_002349e0 { virtual void slot0(); char data[12]; void (*callback)(); char tail[4]; FUN_002349e0(const char* = "variableName"); };
struct FUN_00234cc0 { virtual void slot0(); char data[12]; const char* names; int count; void (*callback)(); char tail[4]; FUN_00234cc0(const char* = "compare"); };
struct FUN_00234960 { virtual void slot0(); char data[12]; void (*callback)(); char tail[4]; FUN_00234960(const char* = "luaValue"); };
class CLuaNumberCondition;
namespace fight {
template<class T> struct ParamString : FUN_002349e0 { virtual void slot0(); };
template<class T> struct ParamEnumConstList : FUN_00234cc0 { virtual void slot0(); };
template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot0(); };
}
extern "C" void __cdecl FUN_002347b0(int*, void**, int);
void FUN_00053ef0() {
 if (!DAT_004dc504) {
 void* params[3];
 void* mem=FUN_0008d690(24);
 fight::ParamString<CLuaNumberCondition>* a = mem ? new(mem) fight::ParamString<CLuaNumberCondition> : 0;
 params[0]=a;
 if(a) a->callback=FUN_00049ed0;
 mem=FUN_0008d690(32);
 fight::ParamEnumConstList<CLuaNumberCondition>* b=0;
 if(mem) { int count=DAT_00427754; b=new(mem) fight::ParamEnumConstList<CLuaNumberCondition>; b->count=count; b->names="lwB"; b->callback=FUN_00047fc0; }
 params[1]=b;
 mem=FUN_0008d690(24);
 fight::ParamFloatConstRange<CLuaNumberCondition>* c = mem ? new(mem) fight::ParamFloatConstRange<CLuaNumberCondition> : 0;
 params[2]=c;
 if(c) c->callback=FUN_00047fd0;
 FUN_002347b0(&DAT_004dc500,params,3);
 }
 ++DAT_004dc504;
}
