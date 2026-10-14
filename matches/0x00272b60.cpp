class B_272b60 {
  public:
    void f();
};
class A_272b60 {
  public:
    char pad[0xb8];
    B_272b60* p;
    void run();
};
void A_272b60::run() {
    p->f();
}