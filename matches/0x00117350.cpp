struct Ref { virtual void Add(); virtual void Release(); };
void Init();
class MotionLocatorAction { public: char pad[0x1c]; volatile unsigned int mArg; Ref* mOld; unsigned int mZero; unsigned int mMin1; unsigned int mMin2; MotionLocatorAction* Build(unsigned int a, Ref* r); };
MotionLocatorAction* MotionLocatorAction::Build(unsigned int a, Ref* r) { Init(); mMin1=0x7f7fffff; mMin2=0x7f7fffff; *(volatile unsigned int*)this=0x40ed2c; mArg=0; mOld=0; mZero=0; mArg=a; if(r) r->Add(); if(mOld) mOld->Release(); mOld=r; return this; }