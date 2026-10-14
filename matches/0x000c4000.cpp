class Sub_c4000 {
  public:
    void F();
};
class Obj_c4000 {
    char pad[0x4c];

  public:
    Sub_c4000* sub;
    void G();
};
class Target_c4000 {
    char pad[4];
    Obj_c4000* obj;

  public:
    int F(int a, int b);
};
int Target_c4000::F(int a, int b) {
    obj->sub->F();
    obj->G();
    return 0;
}