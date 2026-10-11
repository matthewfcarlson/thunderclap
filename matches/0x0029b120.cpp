extern "C" char DAT_0042d548[];
class Base {
  public:
    virtual void Call();
};
class TextString {
  public:
    virtual void V();
    char pad[0x3c];
    Base* obj;
    int x44;
    int a48;
    int a4c;
    unsigned char flag;
    void Init();
    TextString* Foo(Base* p, int a, int b, unsigned char f);
};
TextString* TextString::Foo(Base* p, int a, int b, unsigned char f) {
    Init();
    *(unsigned*)this = ((int)DAT_0042d548);
    this->x44 = -1;
    this->obj = p;
    p->Call();
    this->a48 = a;
    this->a4c = b;
    this->flag = f;
    return this;
}
