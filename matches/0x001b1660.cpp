extern const char strA[], strB[], strC[];
char __cdecl GetFlag(const char*);
class Base {
  public:
    virtual void f();
    Base(void*, int);
    char pad[20];
};
class Function2 : public Base {
  public:
    virtual void g();
    Function2(void*, void*);
    char flag18[4];
    void* target;
};
Function2::Function2(void* a, void* b) : Base(a, 2) {
    target = b;
    flag18[0] = GetFlag(strA);
    ((char*)this)[0x10] = GetFlag(strB);
    ((char*)this)[0x11] = GetFlag(strC);
}
