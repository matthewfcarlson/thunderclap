extern "C" int __cdecl FUN_00344e74(const char*, const char*, const char*, const char*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class RandomKeyWordWaitCondition {};
} // namespace ai
} // namespace hulkfight
extern const char DAT_00491ca8[];
extern const char DAT_004a4290[];
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, DAT_00491ca8, DAT_004a4290, 0) != 0;
}