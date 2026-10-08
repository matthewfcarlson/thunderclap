namespace fight {
class Condition { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); };
class Param { public: virtual void pvfunc_0(); virtual void pvfunc_1(); };
class FalseCondition : public Condition, public Param { public: virtual void vfunc_0(); virtual void vfunc_5(); virtual bool vfunc_6(int, int, int); };
bool FalseCondition::vfunc_6(int, int, int) { return false; }
}