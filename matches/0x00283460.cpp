extern "C" void _ReadWriteBarrier();
class Sub {
  public:
    void Fn(int a, int b, int c);
};
class Target {
    char pad[12];
    Sub* ptr;

  public:
    void Fn(int a, int b, int c);
};
void Target::Fn(int a, int b, int c) {
    ptr->Fn(a, b, c);
    _ReadWriteBarrier();
}