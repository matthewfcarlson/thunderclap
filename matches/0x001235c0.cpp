struct Data {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char pad[0x20];
    int m20;
    int m24;
    int m28;
    bool Set(Data* d);
};
bool Obj::Set(Data* d) {
    m20 = d->a;
    m24 = d->b;
    m28 = d->c;
    return true;
}
