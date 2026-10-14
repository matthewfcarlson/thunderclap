// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_0016ade0 @ 0x0016ade0
typedef unsigned int uint;
void* __cdecl FUN_0008d690(uint);
void __cdecl FUN_00165380(); void __cdecl FUN_00165390(); void __cdecl FUN_001653a0();
extern uint DAT_00427754; extern char DAT_004b4d7c[]; extern uint DAT_004e11d8; extern uint DAT_004e11dc;
void __cdecl FUN_002347b0(void*,void**,int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct ParamBase_16ade0 { void FUN_00234cc0(const char*); void FUN_00234960(const char*); };
namespace hulkfight { namespace motion { class ChargeCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList : ParamBase_16ade0 { virtual void slot0(); char pad[12]; const void* list; uint count; void (*callback)(); uint tail; };
template<class T> struct ParamFloatConstRange : ParamBase_16ade0 { virtual void slot0(); char pad[12]; void (*callback)(); uint tail; };
}
void __cdecl FUN_0016ade0() {
 if (DAT_004e11dc == 0) {
 void* params[3]; void* memory=FUN_0008d690(32); params[0]=memory;
 if(memory) {
 uint count=DAT_00427754;
 ((ParamBase_16ade0*)memory)->FUN_00234cc0("compare");
 typedef fight::ParamEnumConstList<hulkfight::motion::ChargeCondition> E;
 E* p=new(memory) E;
 p->count=count; p->list="lwB"; p->callback=FUN_00165380;
 }
 memory=FUN_0008d690(24); params[1]=memory;
 if(memory) {
 ((ParamBase_16ade0*)memory)->FUN_00234960("charge");
 typedef fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition> F;
 F* p=new(memory) F; p->callback=FUN_00165390;
 }
 memory=FUN_0008d690(32); params[2]=memory;
 if(memory) {
 ((ParamBase_16ade0*)memory)->FUN_00234cc0("type");
 typedef fight::ParamEnumConstList<hulkfight::motion::ChargeCondition> E;
 E* p=new(memory) E;
 p->list=DAT_004b4d7c; p->count=3; p->callback=FUN_001653a0;
 }
 FUN_002347b0(&DAT_004e11d8,params,3);
 }
 ++DAT_004e11dc;
}
