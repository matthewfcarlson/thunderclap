extern int __cdecl Check(void*, int, void*, void*, int);
extern int a;
extern int b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropCollidedWithWorldCondition;
}
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropCollidedWithWorldCondition>::Cast(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}