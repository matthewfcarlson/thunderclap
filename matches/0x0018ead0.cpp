void* __cdecl operator new(unsigned int) throw();
struct Sub {
    Sub() throw();
    char data[8];
};
struct Base {
    Base(int) throw();
    virtual void v0();
    char pad[12];
};
namespace hulkfight {
namespace motion {
struct GrappleVarCompareCondition : Base {
    Sub sub;
    int a, b;
    GrappleVarCompareCondition() throw() : Base(0), sub(), a(0), b(0) {}
    virtual void v0();
};
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> struct ConditionFactoryTemplate {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Base* vfunc_5();
};
template <> Base* ConditionFactoryTemplate<hulkfight::motion::GrappleVarCompareCondition>::vfunc_5() {
    return new hulkfight::motion::GrappleVarCompareCondition();
}
} // namespace fight