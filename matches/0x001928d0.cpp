struct Src {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char p38[0x38];
    int m38;
    int m3c;
    int m40;
    char Set(Src* p);
};
char Obj::Set(Src* p) {
    m38 = p->a;
    m3c = p->b;
    m40 = p->c;
    return 1;
}
