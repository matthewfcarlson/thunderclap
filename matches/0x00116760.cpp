void* g_vftable[7];

namespace fight {
class Condition {
  public:
    void munge();
};
class Param {};
} // namespace fight

void __cdecl opDelete(void* p);

namespace hulkfight {
namespace ai {
class HasGroundPointExtendedCondition : public fight::Condition, public fight::Param {
  public:
    void* vfunc_5(char flag);
};

void* HasGroundPointExtendedCondition::vfunc_5(char flag) {
    HasGroundPointExtendedCondition* self = this;
    *(void**)self = &g_vftable;
    this->fight::Condition::munge();
    if (flag & 1) {
        opDelete(self);
    }
    return self;
}
} // namespace ai
} // namespace hulkfight
