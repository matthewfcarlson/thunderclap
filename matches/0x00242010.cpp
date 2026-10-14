extern "C" unsigned __int64 __cdecl lookup(const char*, int, int);
extern char mixName[];
extern char otherName[];
class Base {
  public:
    virtual void f();
    Base(const unsigned __int64&, const unsigned __int64&, int, int, int);
};
class Mix : public Base {
  public:
    Mix();
    virtual void f();
};
Mix::Mix() : Base(lookup(otherName, 0, 0), lookup(mixName, 0, 0), 0x1000002, 0x50, 8) {}