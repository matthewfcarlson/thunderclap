struct Src {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    char Pad[0x14];
    int x;
    int y;
    int z;
    char Set(Src* p);
};

char Obj::Set(Src* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return 1;
}
