class Ref { public: virtual void Add(); virtual void Release(); };
class CAction { public: CAction(); virtual void F0(); virtual void F1(); virtual void F2(); virtual void F3(); virtual void F4(); virtual void F5(); virtual void F6(); virtual void F7(); char pad[24]; Ref *mRef; int x; };
class CDropAction : public CAction { public: virtual void D0(); virtual void D1(); Ref *mOther; int a; int b; CDropAction(int, Ref *); };
CDropAction::CDropAction(int v, Ref *r) : CAction() { *(int *)this = 0x3f3390; mRef = 0; if (r) r->Add(); if (mRef) mRef->Release(); mRef = r; x = v; *(int *)this = 0x3f3438; mOther = 0; b = 0; }
