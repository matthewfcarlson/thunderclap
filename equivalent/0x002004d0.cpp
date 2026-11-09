// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002004d0 @ 0x002004d0
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/address.h"
#include "decls/data/script.h"

struct CTriggerVolumeManager {};
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct BaseInit : public ScriptFunctionFields { virtual void invoke(float); BaseInit(const char*, int); };
template<class T,class R,class A> struct Method1 : BaseInit { virtual void invoke(A); ScriptMemberFn value; Method1(const char* a,int b):BaseInit(a,b) {} };
template<class T,class R,class A> struct Closure1 : Method1<T,R,A> { virtual void invoke(A); void* other; Closure1(const char* a,void* otherArg,ScriptMemberFn valueArg); };
extern "C" void* DAT_0042551c;
template<> Closure1<CTriggerVolumeManager,void,float>::Closure1(const char* arg,void* otherArg,ScriptMemberFn valueArg) : Method1<CTriggerVolumeManager,void,float>(arg,1) { this->value=valueArg; this->retType=FUN_001d04d0(((char*)&DAT_0048e100)); this->argTypes[0]=FUN_001d04d0(((char*)&DAT_0048e128)); this->other=otherArg; *(void**)this=&DAT_0042551c; }
