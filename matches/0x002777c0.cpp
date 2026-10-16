namespace core {
class ICementLibrary {
  public:
    virtual void vfunc_0();
};
class IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
class CementLibrary : public ICementLibrary, public IRefCount {
  public:
    virtual void vfunc_0();
};
void CementLibrary::vfunc_0() {}
CementLibrary g;
} // namespace core