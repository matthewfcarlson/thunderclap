// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_00054360 @ 0x00054360
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_00048110(); void __cdecl FUN_00048120(); void __cdecl FUN_00048140(); void __cdecl FUN_00048160();
extern unsigned int DAT_00427754; extern unsigned int DAT_004dc54c; extern unsigned int DAT_004dc548; extern char DAT_0048f9d4;
struct CGrappleTimerCondition;
struct Base { virtual void dummy(); char pad[12]; void FUN_00234cc0(const char*); void FUN_00234960(const char*); void FUN_00234860(const char*); };
namespace fight {
template<class T> struct ParamEnumConstList : Base { const void* list; unsigned int count; void (__cdecl *callback)(); unsigned int extra; virtual void dummy(); };
template<class T> struct ParamFloatConstRange : Base { void (__cdecl *callback)(); unsigned int extra; virtual void dummy(); };
template<class T> struct ParamBool : Base { void (__cdecl *callback)(); unsigned int extra; virtual void dummy(); };
}
void __cdecl FUN_002347b0(void*, Base**, int);
void FUN_00054360() {
 if (!DAT_004dc54c) {
 Base* items[4];
 void* mem=FUN_0008d690(32);
 if(mem) { unsigned int n=DAT_00427754; ((Base*)mem)->FUN_00234cc0("compare"); fight::ParamEnumConstList<CGrappleTimerCondition>* p=new(mem) fight::ParamEnumConstList<CGrappleTimerCondition>; p->count=n; p->list="lwB"; p->callback=FUN_00048110; items[0]=p; } else items[0]=0;
 mem=FUN_0008d690(24);
 if(mem) { ((Base*)mem)->FUN_00234960("time"); fight::ParamFloatConstRange<CGrappleTimerCondition>* p=new(mem) fight::ParamFloatConstRange<CGrappleTimerCondition>; p->callback=FUN_00048120; items[1]=p; } else items[1]=0;
 mem=FUN_0008d690(24);
 if(mem) { ((Base*)mem)->FUN_00234860("useKeyWordWait"); fight::ParamBool<CGrappleTimerCondition>* p=new(mem) fight::ParamBool<CGrappleTimerCondition>; p->callback=FUN_00048140; items[2]=p; } else items[2]=0;
 mem=FUN_0008d690(32);
 if(mem) { ((Base*)mem)->FUN_00234cc0("keyWord"); fight::ParamEnumConstList<CGrappleTimerCondition>* p=new(mem) fight::ParamEnumConstList<CGrappleTimerCondition>; p->list=&DAT_0048f9d4; p->count=10; p->callback=FUN_00048160; items[3]=p; } else items[3]=0;
 FUN_002347b0(&DAT_004dc548,items,4);
 }
 ++DAT_004dc54c;
}
