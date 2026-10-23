extern "C" int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
extern char DAT_00491ca8, DAT_004b1f30;
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
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b1f30, 0) != 0;
}