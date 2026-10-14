class Child_99aa0 {
  public:
    int probe();
    void run(int a, int b);
};
class Obj_99aa0 {
  public:
    char pad[0xb8];
    Child_99aa0* member;
    void f(int x);
};
extern int gValue_99aa0;
void Obj_99aa0::f(int x) {
    if (member != 0) {
        int v = member->probe();
        if (v != 0 && x == v)
            member->run(gValue_99aa0, x);
    }
}
