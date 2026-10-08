class CCondition { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); };
class CNameFlagConditionBase : public CCondition { public: char pad[12]; CNameFlagConditionBase* vfunc_5(int); };
class H { public: void a(); void b(); };
extern void vt_name(); extern void vt_cond();
void thunk_FUN_00267090(void*);
CNameFlagConditionBase* CNameFlagConditionBase::vfunc_5(int p) {
 CNameFlagConditionBase* s=this;
 *(void (**)())s=&vt_name;
 ((H*)((char*)s+0x10))->a();
 *(void (**)())s=&vt_cond;
 ((H*)s)->b();
 if(p&1) thunk_FUN_00267090(s);
 return s;
}
