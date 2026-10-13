// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_0018e590 @ 0x0018e590
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0018cb50();
void __cdecl FUN_0018cb60();
void __cdecl FUN_0018cb70();
extern int DAT_00427754;
extern int DAT_004e151c;
extern int DAT_004e1518;
void __cdecl FUN_002347b0(void*,void**,int);
namespace hulkfight { namespace motion { class VarCompareCondition; } }
namespace fight {
template<class T> struct ParamName {
 virtual void slot0();
 char fields[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234a90(const char*);
};
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char fields[12];
 const char* values;
 int count;
 void (__cdecl *callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamIntConstRange {
 virtual void slot0();
 char fields[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_002348e0(const char*);
};
}
void __cdecl FUN_0018e590() {
 if (DAT_004e151c == 0) {
  void* items[3];
  fight::ParamName<hulkfight::motion::VarCompareCondition>* a = (fight::ParamName<hulkfight::motion::VarCompareCondition>*)FUN_0008d690(24);
  if(a) { a->FUN_00234a90("variable"); a = new(a) fight::ParamName<hulkfight::motion::VarCompareCondition>; a->callback = FUN_0018cb50; }
  items[0]=a;
  fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>* b=(fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>*)FUN_0008d690(32);
  if(b) { int count=DAT_00427754; b->FUN_00234cc0("compare"); b->count=count; b = new(b) fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>; b->values="lwB"; b->callback=FUN_0018cb60; }
  items[1]=b;
  fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>* c=(fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>*)FUN_0008d690(24);
  if(c) { c->FUN_002348e0("value"); c = new(c) fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>; c->callback=FUN_0018cb70; }
  items[2]=c;
  FUN_002347b0(&DAT_004e1518,items,3);
 }
 ++DAT_004e151c;
}
