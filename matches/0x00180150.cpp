struct Field {
    int a, b, c;
};
class Obj {
  public:
    char pad[0x80];
    int f80;
    int f84;
    int f88;
    char Set(Field* p);
};
char Obj::Set(Field* p) {
    f80 = p->a;
    f84 = p->b;
    f88 = p->c;
    return 1;
}
