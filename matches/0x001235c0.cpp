struct Data_1235c0 {
    int a;
    int b;
    int c;
};
class Obj_1235c0 {
  public:
    char pad[0x20];
    int m20;
    int m24;
    int m28;
    bool Set(Data_1235c0* d);
};
bool Obj_1235c0::Set(Data_1235c0* d) {
    m20 = d->a;
    m24 = d->b;
    m28 = d->c;
    return true;
}
