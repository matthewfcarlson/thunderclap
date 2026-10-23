extern "C" void* __cdecl FUN_00344e74(void*, long, const void*, const void*, int);
extern char DAT_00491ca8;
extern char DAT_004b20d0;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CollisionDevastatorCondition {};
} // namespace motion
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDevastatorCondition>::Cast(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b20d0, 0) != 0;
}