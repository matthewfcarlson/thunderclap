extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char sourceType, targetType;
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
namespace ai {
class PropsToSuckCondition;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>::vfunc_0(void* p) {
    return __RTDynamicCast(p, 0, &sourceType, &targetType, 0) != 0;
}