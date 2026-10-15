extern char gOne[];
extern char gTwo[];
extern unsigned char __cdecl GetFlag(const char*);
class Base {
  public:
    virtual void V();
    Base(int a, int b) throw();
    char pad[0x1c - 4];
};
class Method1 : public Base {
  public:
    virtual void V();
    Method1(int a, int b) throw();
    unsigned char x;
};
Method1::Method1(int a, int b) throw() : Base(a, 1) {
    *(int*)((char*)this + 0x1c) = b;
    *(unsigned char*)((char*)this + 0x18) = GetFlag(gOne);
    *(unsigned char*)((char*)this + 0x10) = GetFlag(gTwo);
}