extern "C" char DAT_0042921c[];
struct Base_247220 {
    virtual void F();
};
class ContentStream {
  public:
    unsigned vptr, a, b, c, d, e;
    unsigned char flag;
    unsigned char pad[3];
    Base_247220* source;
    ContentStream* Make(Base_247220*);
};
ContentStream* ContentStream::Make(Base_247220* arg) {
    a = 0x2469e0;
    b = 0x2469f0;
    c = 0x246a10;
    d = 0x246a40;
    e = 0x246a60;
    flag = 0;
    vptr = ((int)DAT_0042921c);
    source = arg;
    arg->F();
    return this;
}