class B_1c6200 {
  public:
    void g(void*, int, int, int);
};
class A_1c6200 {
  public:
    char pad[0x284];
    B_1c6200* member;
    void f(void*);
};
void A_1c6200::f(void* param) {
    member->g(param, 3, 4, 1);
}