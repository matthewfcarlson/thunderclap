class Action_239770 {
    char x[0x38];
};
class Base_239770 {
  public:
    void vfunc();
};
class ExecuteAction : public Action_239770, public Base_239770 {
  public:
    void vfunc_4();
};
void ExecuteAction::vfunc_4() {
    Base_239770::vfunc();
}