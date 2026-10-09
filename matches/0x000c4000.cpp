class Sub {
  public:
    void F();
};
class Obj {
    char pad[0x4c];

  public:
    Sub* sub;
    void G();
};
class Target {
    char pad[4];
    Obj* obj;

  public:
    int F(int a, int b);
};
int Target::F(int a, int b) {
    obj->sub->F();
    obj->G();
    return 0;
}