extern "C" int __cdecl Find(void*, void*, void*, void*, void*);
extern char typeA, typeB;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int Check(void*);
    virtual void Other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int Check(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CollisionSourceTypeCondition;
}
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition>::Check(void* p) {
    return Find(p, 0, &typeA, &typeB, 0) != 0;
}