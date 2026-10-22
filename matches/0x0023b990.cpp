class Reader {
  public:
    virtual void f();
    virtual void g();
};
class BinReader_23b990 {
  public:
    virtual void f();
    virtual ~BinReader_23b990();
    void Fin();
    int pad4;
    Reader* reader;
};
void BinReader_23b990::f() {}
BinReader_23b990::~BinReader_23b990() {
    reader->g();
    Fin();
}
