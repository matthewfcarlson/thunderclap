// cl-flags: /O1
class T {
  public:
    virtual void A();
    char Get() throw();
};
char T::Get() throw() {
    return *(char*)((char*)this + 0x1d4d);
}
