struct Entry {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char pad[0x24];
    int m24;
    int m28;
    int m2c;
    bool Set(Entry* e);
};
bool Obj::Set(Entry* e) {
    m24 = e->a;
    m28 = e->b;
    m2c = e->c;
    return true;
}
