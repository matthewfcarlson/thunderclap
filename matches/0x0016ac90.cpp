extern int typeA;
extern int typeB;
extern "C" void* __cdecl castThing(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
class ThinkingCaster : public ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
bool ThinkingCaster::Check(void* p) {
    return castThing(p, 0, &typeA, &typeB, 0) != 0;
}
} // namespace fight