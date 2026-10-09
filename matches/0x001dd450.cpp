class A {
  public:
    int f();
};
class Obj {
  public:
    void g(int);
    void Target(A* arg);
};
void Obj::Target(A* arg) {
    int x = arg->f();
    g(x);
}