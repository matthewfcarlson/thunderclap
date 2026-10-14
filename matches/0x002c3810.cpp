class Impl_2c3810 {
  public:
    void Helper();
};
class Adj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
void Adj::c() {
    Impl_2c3810* p = (Impl_2c3810*)((char*)this + (-16));
    p->Helper();
}
