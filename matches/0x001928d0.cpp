struct Src_1928d0 {
    int a;
    int b;
    int c;
};
class Obj_1928d0 {
  public:
    char p38[0x38];
    int m38;
    int m3c;
    int m40;
    char Set(Src_1928d0* p);
};
char Obj_1928d0::Set(Src_1928d0* p) {
    m38 = p->a;
    m3c = p->b;
    m40 = p->c;
    return 1;
}
