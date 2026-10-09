// Same code shape as 0x000165f0 (propagated; names are from that function)
class Inner2 { public: Inner2* Step2(); void Step3(int); };
class Inner1 { public: Inner2* Step1(); };
class CIntangibleAction { char pad[0x1c]; Inner1* member; public: void vfunc_4(); };
void CIntangibleAction::vfunc_4() { Inner2* p = member->Step1()->Step2(); p->Step3(0); }