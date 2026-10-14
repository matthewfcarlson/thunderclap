class A_1dd450 {
  public:
    int f();
};
class Obj_1dd450 {
  public:
    void g(int);
    void Target(A_1dd450* arg);
};
void Obj_1dd450::Target(A_1dd450* arg) {
    int x = arg->f();
    g(x);
}