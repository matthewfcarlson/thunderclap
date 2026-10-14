struct Src_68650 {
    int a;
    int b;
    int c;
};

class Obj_68650 {
  public:
    char Pad[0x14];
    int x;
    int y;
    int z;
    char Set(Src_68650* p);
};

char Obj_68650::Set(Src_68650* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return 1;
}
