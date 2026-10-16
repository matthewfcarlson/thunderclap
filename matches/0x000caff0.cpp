class Other {
  public:
    void Fn(int, int);
};
class Obj {
    char pad[0x88];
    Other* other;

  public:
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    if (other)
        other->Fn(a, b);
}