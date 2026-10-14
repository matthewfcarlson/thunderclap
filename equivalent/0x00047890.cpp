// STATUS: equivalent (tools/equiv.py level 3: 22 inputs, branch coverage 4/4)
// FUN_00047890 @ 0x00047890
typedef unsigned int uint;
inline void* __cdecl operator new(unsigned int,void* p) { return p; }
void* __cdecl FUN_0008d6d0(uint);
void* __cdecl FUN_0008d690(uint);
extern void* DAT_0048e100;
extern void* DAT_0048e0f0;
unsigned char __cdecl FUN_001d04d0(void*);
struct Registry { void FUN_001d3b70(const char*,void*); };
Registry* __cdecl FUN_001d4c90();
class CCharacterTemplateManager {
public:
 virtual void slot0();
 uint owner,count,used;
 uint* entries;
 void FUN_00046140(const char*);
 CCharacterTemplateManager(uint,uint);
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
CCharacterTemplateManager::CCharacterTemplateManager(uint arg,uint n) {
 owner=arg; count=n; used=0;
 entries=(uint*)FUN_0008d6d0(n*4);
 uint* p=entries;
 uint total=(count*4)>>2;
 for(uint i=0;i<total;++i) p[i]=0;
 Registry* r=FUN_001d4c90();
 if(r) {
  void* mem=FUN_0008d690(36);
  Closure1<CCharacterTemplateManager,void,const char*>* cb=0;
  if(mem) {
   ((CallbackBase*)mem)->FUN_001d0480("ctm_UnloadCharacterTemplate",1);
   Method1<CCharacterTemplateManager,void,const char*>* m=new(mem) Method1<CCharacterTemplateManager,void,const char*>;
   m->method=&CCharacterTemplateManager::FUN_00046140;
   m->result=FUN_001d04d0(&DAT_0048e100);
   m->type=FUN_001d04d0(&DAT_0048e0f0);
   cb=new(mem) Closure1<CCharacterTemplateManager,void,const char*>;
   cb->object=this;
  }
  r->FUN_001d3b70("ctm_UnloadCharacterTemplate",cb);
 }
}
