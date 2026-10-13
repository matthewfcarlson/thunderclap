// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 10/10)
// FUN_00128660 @ 0x00128660
extern int DAT_004e0d80;
extern int DAT_004e0d7c;
extern int DAT_00427754;
extern void* __cdecl FUN_0008d690(unsigned);
extern void FUN_00123620();
extern void FUN_00123630();
extern void FUN_00123650();
extern void FUN_00123670();
inline void* operator new(unsigned, void* p) { return p; }
namespace hulkfight { namespace ai { class TargetDistanceCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 const char* values;
 int count;
 void (*callback)();
 int remaining;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (*callback)();
 int remaining;
 void FUN_00234960(const char*);
};
template<class T> struct ParamBool {
 virtual void slot0();
 char pad[12];
 void (*callback)();
 int remaining;
 void FUN_00234860(const char*);
};
}
extern void __cdecl FUN_002347b0(int*, void**, int);
void target() {
 if (DAT_004e0d80 == 0) {
 void* entries[4];
 typedef fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition> Enum;
 typedef fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition> Float;
 typedef fight::ParamBool<hulkfight::ai::TargetDistanceCondition> Bool;
 Enum* e=(Enum*)FUN_0008d690(32);
 if(e) {
 int n=DAT_00427754;
 e->FUN_00234cc0("compare");
 e->count=n;
 new(e) Enum;
 e->values="lwB";
 e->callback=FUN_00123620;
 }
 entries[0]=e;
 Float* f=(Float*)FUN_0008d690(24);
 if(f) {
 f->FUN_00234960("distance");
 new(f) Float;
 f->callback=FUN_00123630;
 }
 entries[1]=f;
 Bool* b=(Bool*)FUN_0008d690(24);
 if(b) {
 b->FUN_00234860("useHulk");
 new(b) Bool;
 b->callback=FUN_00123650;
 }
 entries[2]=b;
 b=(Bool*)FUN_0008d690(24);
 if(b) {
 b->FUN_00234860("useGroundPoint");
 new(b) Bool;
 b->callback=FUN_00123670;
 }
 entries[3]=b;
 FUN_002347b0(&DAT_004e0d7c, entries, 4);
 }
 ++DAT_004e0d80;
}
