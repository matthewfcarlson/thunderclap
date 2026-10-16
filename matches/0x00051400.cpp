int __cdecl Check(void*, int, void*, void*, int);
extern void* gA;
extern void* gB;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool Test(void*);
    virtual void Other();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool Test(void*);
    virtual void Other();
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::Test(void* p) {
    return Check(p, 0, &gA, &gB, 0) != 0;
}