// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 10/10)
// FUN_001123a0 @ 0x001123a0
inline void* operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0010c2c0(); void __cdecl FUN_0010c2e0(); void __cdecl FUN_0010c300(); void __cdecl FUN_0010c320();
extern int DAT_00427754; extern int DAT_004e0b44; extern int DAT_004e0b40;
namespace hulkfight { namespace ai { class PropsToSuckCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); char pad[12]; const char* list; int count; void (__cdecl *callback)(); int tail; void FUN_00234cc0(const char*); };
template<class T> struct ParamFloatConstRange { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); char pad[12]; void (__cdecl *callback)(); int tail; void FUN_00234960(const char*); };
template<class T> struct ParamBool { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); char pad[12]; void (__cdecl *callback)(); int tail; void FUN_00234860(const char*); };
template<class T> struct ParamIntConstRange { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); char pad[12]; void (__cdecl *callback)(); int tail; void FUN_002348e0(const char*); };
}
void __cdecl FUN_002347b0(int*, void**, int);
void target() {
 if (DAT_004e0b44 == 0) {
 void* params[4]; typedef hulkfight::ai::PropsToSuckCondition T;
 fight::ParamEnumConstList<T>* a=(fight::ParamEnumConstList<T>*)FUN_0008d690(32);
 if(a) { int count=DAT_00427754; a->FUN_00234cc0("compare"); a->count=count; new(a) fight::ParamEnumConstList<T>; a->list="lwB"; a->callback=FUN_0010c2c0; } params[0]=a;
 fight::ParamFloatConstRange<T>* b=(fight::ParamFloatConstRange<T>*)FUN_0008d690(24);
 if(b) { b->FUN_00234960("distance"); new(b) fight::ParamFloatConstRange<T>; b->callback=FUN_0010c2e0; } params[1]=b;
 fight::ParamBool<T>* c=(fight::ParamBool<T>*)FUN_0008d690(24);
 if(c) { c->FUN_00234860("numberofAttachedProps"); new(c) fight::ParamBool<T>; c->callback=FUN_0010c300; } params[2]=c;
 fight::ParamIntConstRange<T>* d=(fight::ParamIntConstRange<T>*)FUN_0008d690(24);
 if(d) { d->FUN_002348e0("number"); new(d) fight::ParamIntConstRange<T>; d->callback=FUN_0010c320; } params[3]=d;
 FUN_002347b0(&DAT_004e0b40,params,4);
 } ++DAT_004e0b44;
}
