class Inner_89820 {
  public:
    void Run(int);
};
class Outer_89820 {
  public:
    char pad[0xa8];
    Inner_89820 inner;
    void Forward(int);
};
void Outer_89820::Forward(int a0) {
    inner.Run(a0);
}
