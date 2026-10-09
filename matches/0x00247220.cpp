struct Base {
    virtual void F();
};
class ContentStream {
  public:
    unsigned vptr, a, b, c, d, e;
    unsigned char flag;
    unsigned char pad[3];
    Base* source;
    ContentStream* Make(Base*);
};
ContentStream* ContentStream::Make(Base* arg) {
    a = 0x2469e0;
    b = 0x2469f0;
    c = 0x246a10;
    d = 0x246a40;
    e = 0x246a60;
    flag = 0;
    vptr = 0x42921c;
    source = arg;
    arg->F();
    return this;
}