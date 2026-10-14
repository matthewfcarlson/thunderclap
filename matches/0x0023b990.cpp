class Reader {
  public:
    virtual void f();
    virtual void g();
};
class Obj_23b990 {
  public:
    virtual void f();
    virtual ~Obj_23b990();
    void Fin();
    int pad4;
    Reader* reader;
};
void Obj_23b990::f() {}
Obj_23b990::~Obj_23b990() {
    reader->g();
    Fin();
}
