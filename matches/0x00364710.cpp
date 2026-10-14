class Base_364710 {
  public:
    void Fn();
};
class Obj_364710 : public Base_364710 {
  public:
    void Fn();
};
extern Base_364710 g_base_364710;
void Obj_364710::Fn() {
    ((Base_364710*)&g_base_364710)->Fn();
}
