extern char gName[];
extern "C" unsigned char __cdecl readChar(const char*);
class Base {
  public:
    Base(int, int);
    virtual void f();
    char pad[0x14];
};
class Function2 : public Base {
  public:
    Function2(int, int);
    virtual void f();
    char val18;
    char pad2[3];
    int value;
};
Function2::Function2(int a, int b) : Base(a, 2) {
    value = b;
    val18 = readChar(gName);
    *(unsigned char*)((char*)this + 0x10) = readChar(gName);
    *(unsigned char*)((char*)this + 0x11) = readChar(gName);
}