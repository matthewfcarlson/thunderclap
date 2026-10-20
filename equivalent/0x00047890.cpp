// STATUS: equivalent (tools/equiv.py level 3: 22 inputs, branch coverage 4/4)
// FUN_00047890 @ 0x00047890
#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned int uint_47890;
inline void* __cdecl operator new(unsigned int,void* p) { return p; }
void* __cdecl FUN_0008d6d0(uint_47890);
void* __cdecl FUN_0008d690(uint_47890);
struct Registry_47890 { void FUN_001d3b70(const char*,void*); };
Registry_47890* __cdecl FUN_001d4c90();
class CCharacterTemplateManager {
public:
 virtual void slot0();
 uint_47890 owner,count,used;
 uint_47890* entries;
 void FUN_00046140(const char*);
 CCharacterTemplateManager(uint_47890,uint_47890);
};
template<class T,class R,class A> class Method1 {
public:
 virtual void slot0();
 char pad[12];
 unsigned char type;
 char pad2[7];
 unsigned char result;
 char pad3[3];
 void (T::*method)(A);
};
template<class T,class R,class A> class Closure1 : public Method1<T,R,A> {
public:
 T* object;
};
struct CallbackBase { void FUN_001d0480(const char*,int); };
CCharacterTemplateManager::CCharacterTemplateManager(uint_47890 arg,uint_47890 n) {
 owner=arg; count=n; used=0;
 entries=(uint_47890*)FUN_0008d6d0(n*4);
 uint_47890* p=entries;
 uint_47890 total=(count*4)>>2;
 for(uint_47890 i=0;i<total;++i) p[i]=0;
 Registry_47890* r=FUN_001d4c90();
 if(r) {
  void* mem=FUN_0008d690(36);
  Closure1<CCharacterTemplateManager,void,const char*>* cb=0;
  if(mem) {
   ((CallbackBase*)mem)->FUN_001d0480("ctm_UnloadCharacterTemplate",1);
   Method1<CCharacterTemplateManager,void,const char*>* m=new(mem) Method1<CCharacterTemplateManager,void,const char*>;
   m->method=&CCharacterTemplateManager::FUN_00046140;
   m->result=FUN_001d04d0(((void**)&DAT_0048e100));
   m->type=FUN_001d04d0(((void**)&DAT_0048e0f0));
   cb=new(mem) Closure1<CCharacterTemplateManager,void,const char*>;
   cb->object=this;
  }
  r->FUN_001d3b70("ctm_UnloadCharacterTemplate",cb);
 }
}
