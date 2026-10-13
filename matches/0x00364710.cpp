class Base {
  public:
    void Fn();
};
class Obj : public Base {
  public:
    void Fn();
};
extern Base g_base;
void Obj::Fn() {
    ((Base*)&g_base)->Fn();
}
