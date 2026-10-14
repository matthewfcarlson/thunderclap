// cl-flags: /O1
class T_23c80 {
  public:
    virtual void A();
    char Get() throw();
};
char T_23c80::Get() throw() {
    return *(char*)((char*)this + 0x1d4d);
}
