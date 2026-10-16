extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern int srcType, dstType;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class OnBlockedTriangleCondition;
}
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::OnBlockedTriangleCondition>::Check(void* p) {
    return __RTDynamicCast(p, 0, &srcType, &dstType, 0) != 0;
}