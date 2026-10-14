struct Src_146a70 {
    int a, b, c;
};

class Owner_146a70 {
  public:
    char pad[0x10];
    int m10, m14, m18;
    char Set(Src_146a70* p);
};

char Owner_146a70::Set(Src_146a70* p) {
    m10 = p->a;
    m14 = p->b;
    m18 = p->c;
    return 1;
}