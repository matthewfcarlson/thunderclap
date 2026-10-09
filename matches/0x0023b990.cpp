class Reader {
  public:
    virtual void f();
    virtual void g();
};
class Obj {
  public:
    virtual void f();
    virtual ~Obj();
    void Fin();
    int pad4;
    Reader* reader;
};
void Obj::f() {}
Obj::~Obj() {
    reader->g();
    Fin();
}
