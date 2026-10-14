class Inner_89820 {
  public:
    void Run();
};
class Outer_89820 {
  public:
    char pad[0xa8];
    Inner_89820 inner;
    void Forward();
};
void Outer_89820::Forward() {
    inner.Run();
}
