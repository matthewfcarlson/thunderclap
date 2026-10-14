// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_000540a0 @ 0x000540a0
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern int DAT_004dc52c;
extern int DAT_00427760;
extern char DAT_00427758;
extern char DAT_0048f9c0;
extern int DAT_004dc528;
void FUN_00048060();
void FUN_00048070();
void* __cdecl FUN_0008d690(unsigned int);
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 const void* values;
 int count;
 void (*callback)();
 int trailing;
 void FUN_00234cc0(const char*);
};
}
class CMotionHitCondition;
typedef fight::ParamEnumConstList<CMotionHitCondition> Entry;
void __cdecl FUN_002347b0(void*,Entry**,int);
void __cdecl target() {
 if (DAT_004dc52c == 0) {
  Entry* entries[2];
  Entry* p = (Entry*)FUN_0008d690(32);
  if (p) {
   int n = DAT_00427760;
   p->FUN_00234cc0("compare");
   new (p) Entry;
   p->count=n;
   p->values=&DAT_00427758;
   p->callback=FUN_00048060;
  }
  entries[0]=p;
  p=(Entry*)FUN_0008d690(32);
  if (p) {
   p->FUN_00234cc0("motionHit");
   new (p) Entry;
   p->values=&DAT_0048f9c0;
   p->count=5;
   p->callback=FUN_00048070;
  }
  entries[1]=p;
  FUN_002347b0(&DAT_004dc528,entries,2);
 }
 ++DAT_004dc52c;
}
