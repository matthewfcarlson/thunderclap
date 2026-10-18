class Impl_2c3810 {
  public:
    void Helper(int);
};
class Adj {
  public:
    virtual void a();
    virtual void b();
    virtual void c(int);
};
void Adj::c(int a0) {
    Impl_2c3810* p = (Impl_2c3810*)((char*)this + (-16));
    p->Helper(a0);
}
