class B_1d64a0 {
  public:
    int G();
};
class A_1d64a0 {
  public:
    char pad[0xec];
    B_1d64a0* p;
    int F();
};
int A_1d64a0::F() {
    return p->G();
}