class Pad {
    char x[0x38];
};
class Base {
  public:
    void vfunc();
};
class ExecuteAction : public Pad, public Base {
  public:
    void vfunc_4();
};
void ExecuteAction::vfunc_4() {
    Base::vfunc();
}