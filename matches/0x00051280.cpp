class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void* a);
    virtual int vfunc_1(void* a);
};

template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void* a);
};

int TypeCompare(void* a, int f, void* typeA, void* typeB, int g);

int ConditionFactoryCasterTemplate<class CSmartPropCSMableCondition>::vfunc_0(void* a) {
    return (TypeCompare(a, 0, (void*)0x491ca8, (void*)0x493fd0, 0) != 0);
}
