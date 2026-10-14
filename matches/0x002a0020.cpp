class Worker_2a0020 {
  public:
    int get();
};
class Thing_2a0020 {
  public:
    char pad[0x44];
    Worker_2a0020* member;
    void f(int a, int b);
    void apply(int x, int a, int b);
};
void Thing_2a0020::f(int a, int b) {
    int x = member->get();
    apply(x, a, b);
}