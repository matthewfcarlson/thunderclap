extern "C" void* __cdecl cast_runtime(void*, long, const void*, const void*, int);
extern char source_type;
extern char target_type;
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
    return cast_runtime(p, 0, &source_type, &target_type, 0) != 0;
}