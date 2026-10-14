class Sub {
  public:
    char pad[4];
    unsigned char flag;
};
class Inner {
  public:
    unsigned Get();
    void Set(unsigned);
};
class Obj {
  public:
    char pad[4];
    Sub* a;
    Inner* inner;
    Sub* b;
    void Run(unsigned bits);
};
void Obj::Run(unsigned bits) {
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