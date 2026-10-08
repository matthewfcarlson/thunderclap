class FEThing { public: int x; void* m; };
class Target { public: void go(); };
class FEDoAction { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); };
class FEDoPopDialog : public FEDoAction { public: char pad[0x10 - sizeof(FEDoAction)]; FEThing* mThing; virtual void vfunc_0(); virtual void vfunc_1(); };
void FEDoPopDialog::vfunc_1() { ((Target*)mThing->m)->go(); }