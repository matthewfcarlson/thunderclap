class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void* a);
    virtual int vfunc_1(void* a);
};

template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void* a);
};

int FUN_00344e74(void* a, int f, void* typeA, void* typeB, int g);

template <> int ConditionFactoryCasterTemplate<class CSmartPropCSMableCondition>::vfunc_0(void* a) {
    return (FUN_00344e74(a, 0, (void*)0x491ca8, (void*)0x493fd0, 0) != 0);
}
