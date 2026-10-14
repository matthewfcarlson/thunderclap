struct Data {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char f(Data* p);
    char pad[0x1c];
    int m1c;
    int m20;
    int m24;
};
char Obj::f(Data* p) {
    m1c = p->a;
    m20 = p->b;
    m24 = p->c;
    return 1;
}
