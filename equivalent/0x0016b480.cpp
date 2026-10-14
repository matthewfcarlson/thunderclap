// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0016b480 @ 0x0016b480
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern unsigned int DAT_004e122c;
extern unsigned int DAT_00427754;
extern unsigned int DAT_004e1228;
extern char DAT_0042773c[];
extern char DAT_004b4d98[];
extern "C" void FUN_001655a0();
extern "C" void FUN_001655b0();
namespace hulkfight { namespace motion { class GrappleReactionTypeCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 void* values;
 unsigned int count;
 void (*callback)();
 unsigned int tail;
 void FUN_00234cc0(const char*);
};
}
typedef fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition> Param;
extern "C" void __cdecl FUN_002347b0(void*, Param**, int);
void __cdecl FUN_0016b480() {
 if (!DAT_004e122c) {
  Param* entries[2];
  Param* p = (Param*)FUN_0008d690(32);
  if (p) {
   unsigned int count = DAT_00427754;
   p->FUN_00234cc0("compare");
   p = new(p) Param;
   p->count = count;
   p->values = DAT_0042773c;
   p->callback = FUN_001655a0;
  }
  entries[0] = p;
  p = (Param*)FUN_0008d690(32);
  if(p) {
   p->FUN_00234cc0("constant");
   p = new(p) Param;
   p->values = DAT_004b4d98;
   p->count = 3;
   p->callback = FUN_001655b0;
  }
  entries[1] = p;
  FUN_002347b0(&DAT_004e1228, entries, 2);
 }
 ++DAT_004e122c;
}
