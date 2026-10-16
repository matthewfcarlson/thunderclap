class Child {
  public:
    void act();
};
class Obj {
  public:
    int pad;
    Child* child;
    int fn(int a, int b);
};
int Obj::fn(int a, int b) {
    if (!child)
        return -1;
    child->act();
    return 0;
}