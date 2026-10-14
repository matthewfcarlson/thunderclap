class B_265590 {
  public:
    void First();
    void Second();
};
class A_265590 {
  public:
    char pad[12];
    B_265590* x;
    B_265590* y;
    void Run();
};
void A_265590::Run() {
    x->First();
    y->Second();
}