struct Entry_67f60 {
    int a;
    int b;
    int c;
};
class Obj_67f60 {
  public:
    char pad[0x24];
    int m24;
    int m28;
    int m2c;
    bool Set(Entry_67f60* e);
};
bool Obj_67f60::Set(Entry_67f60* e) {
    m24 = e->a;
    m28 = e->b;
    m2c = e->c;
    return true;
}
