extern "C" void _ReadWriteBarrier();
class Sub {
  public:
    void Call(int a, int b);
};
class Thing {
  public:
    char pad[8];
    Sub* field;
    void Fn(int a, int b);
};
void Thing::Fn(int a, int b) {
    field->Call(a, b);
    _ReadWriteBarrier();
}