extern "C" int CastCheck(void*, int, void*, void*, int);

class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void* obj);
    virtual int vfunc_1(void* obj);
};

template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    int vfunc_0(void* obj);
};

template <> int ConditionFactoryCasterTemplate<void>::vfunc_0(void* obj) {
    return (CastCheck(obj, 0, (void*)0x491ca8, (void*)0x492c90, 0) != 0);
}
