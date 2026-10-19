void __cdecl Cleanup(int);
class PathLocatorTestCondition {
  public:
    int a, b;
    virtual ~PathLocatorTestCondition();
    int d;
    virtual void hulk_slot_F(); void F();
};
PathLocatorTestCondition::~PathLocatorTestCondition() {
    Cleanup(d);
    F();
}