extern "C" int __cdecl CastCheck(void*, int, void*, void*, int);
extern void* table1;
extern void* table2;
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
class WallVelocityCondition {};
} // namespace motion
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::WallVelocityCondition>::vfunc_0(void* p) {
    return CastCheck(p, 0, &table1, &table2, 0) != 0;
}