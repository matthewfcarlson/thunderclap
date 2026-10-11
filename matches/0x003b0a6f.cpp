extern void* vt[];
class G {
  public:
    void* vptr;
    void Reg(void*) throw();
};
extern G g;
class O {
  public:
    void* vptr;
    O* ctor() throw();
};
O* O::ctor() throw() {
    vptr = vt;
    g.Reg(this);
    return this;
}
