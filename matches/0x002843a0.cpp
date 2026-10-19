extern "C" void _ReadWriteBarrier();
class Sub {
  public:
    int Call(int a, int b);
};
class Thing {
  public:
    char pad[8];
    Sub* field;
    int Fn(int a, int b);
};
int Thing::Fn(int a, int b) {
    int r_ret = field->Call(a, b);
    _ReadWriteBarrier();
    return r_ret;
}