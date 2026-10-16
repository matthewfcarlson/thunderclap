extern char gType1;
extern char gType2;
extern "C" void* __cdecl DynamicCast(void*, int, const void*, const void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CollisionTargetSizeCondition {};
} // namespace motion
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_0(
    void* p) {
    return DynamicCast(p, 0, &gType1, &gType2, 0) != 0;
}
