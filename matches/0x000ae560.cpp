extern char controller_vftable, ref_vftable;
class CController { public: virtual void f0(); virtual void f1(); virtual CController* vfunc_2(int); void second(); };
void FUN_000ad990();
void thunk_FUN_00267090(CController*);
CController* CController::vfunc_2(int param_2) { *(void**)this = &controller_vftable; FUN_000ad990(); second(); *(void**)this = &ref_vftable; if (param_2 & 1) thunk_FUN_00267090(this); return this; }