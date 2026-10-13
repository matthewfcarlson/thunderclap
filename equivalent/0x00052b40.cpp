// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 8/8)
// FUN_00052b40 @ 0x00052b40
inline void* __cdecl operator new(unsigned,void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned);
extern "C" void FUN_00047b00();
extern "C" void FUN_00047b30();
extern "C" void FUN_00047b40();
extern int DAT_00427754;
extern char DAT_0042773c[];
extern char DAT_0049ee74[];
extern int DAT_004dc418;
extern unsigned DAT_004dc41c;
extern "C" void __cdecl FUN_002347b0(void*,void**,int);
class CAxisSpeedCondition;
struct EnumBase {
 virtual void slot0();
 char pad[12];
 void FUN_00234cc0(const char*);
};
struct FloatBase {
 virtual void slot0();
 char pad[12];
 void FUN_00234960(const char*);
};
namespace fight {
template<class T> struct ParamEnumConstList: EnumBase {
 const char* values; int count; void (*callback)(); int tail;
 virtual void slot0();
};
template<class T> struct ParamFloatConstRange: FloatBase {
 void (*callback)(); int tail;
 virtual void slot0();
};
}
void FUN_00052b40() {
 if (!DAT_004dc41c) {
 void* list[3];
 fight::ParamEnumConstList<CAxisSpeedCondition>* a=(fight::ParamEnumConstList<CAxisSpeedCondition>*)FUN_0008d690(32);
 if(a) { a->FUN_00234cc0("axis"); a = new(a) fight::ParamEnumConstList<CAxisSpeedCondition>; a->values=DAT_0049ee74; a->count=2; a->callback=FUN_00047b00; }
 list[0]=a;
 fight::ParamEnumConstList<CAxisSpeedCondition>* b=(fight::ParamEnumConstList<CAxisSpeedCondition>*)FUN_0008d690(32);
 if(b) { int count=DAT_00427754; b->FUN_00234cc0("compareSpeed"); b = new(b) fight::ParamEnumConstList<CAxisSpeedCondition>; b->count=count; b->values=DAT_0042773c; b->callback=FUN_00047b30; }
 list[1]=b;
 fight::ParamFloatConstRange<CAxisSpeedCondition>* c=(fight::ParamFloatConstRange<CAxisSpeedCondition>*)FUN_0008d690(24);
 if(c) { c->FUN_00234960("speed"); c = new(c) fight::ParamFloatConstRange<CAxisSpeedCondition>; c->callback=FUN_00047b40; }
 list[2]=c;
 FUN_002347b0(&DAT_004dc418,list,3);
 }
 ++DAT_004dc41c;
}