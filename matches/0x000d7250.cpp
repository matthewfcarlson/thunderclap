class Sub_d7250 {
  public:
    char pad[4];
    unsigned char flag;
};
class Inner_d7250 {
  public:
    unsigned Get();
    void Set(unsigned);
};
class Obj_d7250 {
  public:
    char pad[4];
    Sub_d7250* a;
    Inner_d7250* inner;
    Sub_d7250* b;
    void Run(unsigned bits);
};
void Obj_d7250::Run(unsigned bits) {
    unsigned x = inner->Get() & ~0x80u;
    if (a)
        x |= 0x80;
    if (b)
        x |= 0x100;
    unsigned result = x | bits;
    inner->Set(result);
    a->flag = (result >> 7) & 1;
    b->flag = (result >> 8) & 1;
}