class Ref { public: virtual void A(); virtual void B(); };
extern int vtable;
struct Base { void InitBase(); };
struct LocomotionStrafeAction : Base { char pad[0x1c]; Ref* mRef; int mOther; LocomotionStrafeAction* Init(Ref*); };
LocomotionStrafeAction* LocomotionStrafeAction::Init(Ref* p) { InitBase(); *(int*)this=(int)&vtable; mRef=0; mOther=0; if(p) p->A(); if(mRef) mRef->B(); mRef=p; return this; }