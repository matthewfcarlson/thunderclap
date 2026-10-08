struct A { A* get(); void init(); int check(); };
struct Result { void apply(int, int); };
struct FlyingAttackAction {
 char pad[0x1c]; A* mAt20; int mAt24;
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void vfunc4(); virtual void v5();
 void mid();
};
void FlyingAttackAction::vfunc4() {
 A* edi = mAt20->get();
 edi->init();
 mid();
 int result = edi->check();
 if (result) ((Result*)result)->apply(mAt24, 0);
}