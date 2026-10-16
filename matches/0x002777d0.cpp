namespace core {
class ICementLibrary {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
class IRefCount {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
extern void work(void*);
class __declspec(dllexport) CementLibrary : public ICementLibrary, public IRefCount {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
void CementLibrary::b() {
    work(this);
}
} // namespace core