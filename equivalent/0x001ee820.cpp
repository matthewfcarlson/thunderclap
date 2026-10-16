// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_001ee820 @ 0x001ee820
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
typedef unsigned int size_t;
void* __cdecl operator new(size_t, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned);
struct Owner { void FUN_001f2c00(unsigned); };
class CSoundRealTimeManager { public:
 Owner* owner; unsigned id;
 void FUN_001ee820();
 void FUN_001eb550(); void FUN_001eb560(const char*); void FUN_001eb6c0(const char*);
 void FUN_001eb130(float); void FUN_001eb140(bool); void FUN_001eb150(float); void FUN_001eb160(float);
 void FUN_001eb740(char*,char*,char*); void FUN_001eb870(); void FUN_001eb890(); void FUN_001eb8d0(char*); void FUN_001eb950(char*);
};
struct __declspec(novtable) Command {
 virtual void slot0();
 char pad4[12]; unsigned char argumentType; char pad17[7]; unsigned char returnType; char pad25[3];
 void FUN_001d0480(const char*,int);
 void FUN_001edcf0(const char*, void (CSoundRealTimeManager::*)(char*,char*,char*));
 Command(const char* name) { FUN_001d0480(name,1); }
 Command(const char* name,void(CSoundRealTimeManager::*fn)(char*,char*,char*)) { FUN_001edcf0(name,fn); }
};
template<class C,class R,class A> class Method1: public Command { public:
 void (C::*method)(A);
 virtual void slot0();
 Method1(const char* name,void(C::*fn)(A),const void* type):Command(name) {
 method=fn; returnType=FUN_001d04d0(((int*)&DAT_0048e100)); argumentType=FUN_001d04d0(type);
 }
};
template<class C,class R,class A> class Closure1: public Method1<C,R,A> { public:
 C* object; virtual void slot0();
 Closure1(const char* name,C* obj,void(C::*fn)(A),const void* type):Method1<C,R,A>(name,fn,type) {object=obj;}
};
template<class C,class R,class A,class B,class D> class Closure3: public Command { public:
 void(C::*method)(A,B,D); C* object; virtual void slot0();
 Closure3(const char* name,C* obj,void(C::*fn)(A,B,D)):Command(name,fn) {object=obj;}
};
struct Registry {
 void FUN_001d3b70(const char*,Command*);
 void FUN_001ee5b0(const char*,CSoundRealTimeManager*,void(CSoundRealTimeManager::*)());
};
Registry* __cdecl FUN_001d4c90();
#define ADD1(N,A,F,T) { void* mem=FUN_0008d690(36); Command* cmd=0; if(mem) cmd=new(mem) Closure1<CSoundRealTimeManager,void,A>(N,this,&CSoundRealTimeManager::F,&T); registry->FUN_001d3b70(N,cmd); }
void CSoundRealTimeManager::FUN_001ee820() {
 owner->FUN_001f2c00(id);
 Registry* registry=FUN_001d4c90();
 ADD1("snd_TriggerMusic",const char*,FUN_001eb560,(*(int*)&DAT_0048e0f0))
 registry->FUN_001ee5b0("snd_StopMusic",this,&CSoundRealTimeManager::FUN_001eb550);
 ADD1("snd_TriggerAmbience",const char*,FUN_001eb6c0,(*(int*)&DAT_0048e0f0))
 ADD1("snd_SetMusicVolume",float,FUN_001eb130,(*(int*)&DAT_0048e128))
 ADD1("snd_LockTransitions",bool,FUN_001eb140,(*(int*)&DAT_0048e0e4))
 {void* mem=FUN_0008d690(36); Command* cmd=0; if(mem) cmd=new(mem) Closure3<CSoundRealTimeManager,void,char*,char*,char*>("snd_PlayDialogue",this,&CSoundRealTimeManager::FUN_001eb740); registry->FUN_001d3b70("snd_PlayDialogue",cmd);}
 ADD1("snd_InstallMix",char*,FUN_001eb8d0,(*(int*)&DAT_0049cad8))
 ADD1("snd_InstallEffect",char*,FUN_001eb950,(*(int*)&DAT_0049cad8))
 ADD1("snd_Set_UserHealthDown",float,FUN_001eb150,(*(int*)&DAT_0048e128))
 ADD1("snd_Set_UserHealthNearDeath",float,FUN_001eb160,(*(int*)&DAT_0048e128))
 registry->FUN_001ee5b0("snd_Mute",this,&CSoundRealTimeManager::FUN_001eb870);
 registry->FUN_001ee5b0("snd_UnMute",this,&CSoundRealTimeManager::FUN_001eb890);
}
