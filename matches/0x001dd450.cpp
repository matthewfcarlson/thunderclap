class A_1dd450 {
  public:
    int f();
};
class CSPManager_1dd450 {
  public:
    void g(int);
    void Target(A_1dd450* arg);
};
void CSPManager_1dd450::Target(A_1dd450* arg) {
    int x = arg->f();
    g(x);
}