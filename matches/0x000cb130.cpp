struct V {
    int a, b, c;
};
class Owner {
    char pad[0x88];

  public:
    class Other* other;
    void Fn(int x, int y, V v);
};
class Other {
  public:
    void Go(int x, int y, V v);
};
void Owner::Fn(int x, int y, V v) {
    if (other)
        other->Go(x, y, v);
}