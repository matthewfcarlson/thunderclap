struct Data {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char pad[0x68];
    Data d;
    bool Set(Data* src);
};
bool Obj::Set(Data* src) {
    d.a = src->a;
    d.b = src->b;
    d.c = src->c;
    return true;
}
