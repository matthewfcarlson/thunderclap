class Inner {
  public:
    void Run();
};
class Outer {
  public:
    char pad[0xa8];
    Inner inner;
    void Forward();
};
void Outer::Forward() {
    inner.Run();
}
