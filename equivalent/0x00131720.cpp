// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 10/10)
// FUN_00131720 @ 0x00131720
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
namespace hulkfight { class ChapterMissionCondition; }
void* __cdecl FUN_0008d690(unsigned int);
void FUN_0012e050(); void FUN_0012e060(); void FUN_0012e080(); void FUN_0012e090();
extern int DAT_00427754, DAT_004e0e78, DAT_004e0e74;
void __cdecl FUN_002347b0(void*,void*,int);
struct FUN_00234cc0 { virtual void slot0(); char base[12]; FUN_00234cc0(const char*); };
struct FUN_002348e0 { virtual void slot0(); char base[12]; FUN_002348e0(const char*); };
namespace fight {
template<class T> struct ParamEnumConstList : FUN_00234cc0 {
 virtual void slot0();
 const char* values; int count; void (*callback)(); int tail;
 ParamEnumConstList(const char* s) : FUN_00234cc0(s) {}
};
template<class T> struct ParamIntConstRange : FUN_002348e0 {
 virtual void slot0();
 void (*callback)(); int tail;
 ParamIntConstRange(const char* s) : FUN_002348e0(s) {}
};
}
typedef fight::ParamEnumConstList<hulkfight::ChapterMissionCondition> Enum_131720;
typedef fight::ParamIntConstRange<hulkfight::ChapterMissionCondition> Range_131720;
void FUN_00131720() {
 if (DAT_004e0e78 == 0) {
  void* list[4];
  Enum_131720* a=(Enum_131720*)FUN_0008d690(32);
  if(a) { int count=DAT_00427754; a=new(a) Enum_131720("chapterCompare"); a->values="lwB"; a->count=count; a->callback=FUN_0012e050; } list[0]=a;
  Range_131720* b=(Range_131720*)FUN_0008d690(24);
  if(b) { b=new(b) Range_131720("chapter"); b->callback=FUN_0012e060; } list[1]=b;
  Enum_131720* c=(Enum_131720*)FUN_0008d690(32);
  if(c) { int count=DAT_00427754; c=new(c) Enum_131720("missionCompare"); c->values="lwB"; c->count=count; c->callback=FUN_0012e080; } list[2]=c;
  Range_131720* d=(Range_131720*)FUN_0008d690(24);
  if(d) { d=new(d) Range_131720("mission"); d->callback=FUN_0012e090; } list[3]=d;
  FUN_002347b0(&DAT_004e0e74,list,4);
 }
 ++DAT_004e0e78;
}
