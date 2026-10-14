extern void* vt_3b0a6f[];
class G_3b0a6f {
  public:
    void* vptr;
    void Reg(void*) throw();
};
extern G_3b0a6f g_3b0a6f;
class O_3b0a6f {
  public:
    void* vptr;
    O_3b0a6f* ctor() throw();
};
O_3b0a6f* O_3b0a6f::ctor() throw() {
    vptr = vt_3b0a6f;
    g_3b0a6f.Reg(this);
    return this;
}
