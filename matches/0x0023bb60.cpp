class Obj {
  public:
    virtual void a();
    virtual void b();
};
class BinReader {
  public:
    virtual void a();
    virtual void b();
    virtual ~BinReader();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    char pad[4];
    Obj* obj;
    void helper();
};
BinReader::~BinReader() {
    obj->b();
    helper();
}