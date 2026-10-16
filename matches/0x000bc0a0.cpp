class Owner {
  public:
    void Action();
};
class Obj {
  public:
    int pad;
    Owner* owner;
    int Fn(int a, int b);
};
int Obj::Fn(int a, int b) {
    owner->Action();
    return 0;
}