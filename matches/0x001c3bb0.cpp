class B_1c3bb0 {
  public:
    void g(int);
};
class A_1c3bb0 {
  public:
    char pad[12];
    B_1c3bb0* member;
    void* f(int);
};
class C_1c3bb0 {
  public:
    char pad[12];
    A_1c3bb0* member;
    void run(int, int);
};
void C_1c3bb0::run(int a, int b) {
    B_1c3bb0* p = (B_1c3bb0*)member->f(a);
    if (p)
        p->g(b);
}