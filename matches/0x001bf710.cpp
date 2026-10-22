extern char gOne[];
extern char gTwo[];
extern "C" char __cdecl ReadFlag(const char*);
class Function_1bf710 {
  public:
    Function_1bf710(int, int);
    virtual void Fn();
    char pad[0xc];
    char f10, f11, f12;
    char pad2[5];
    char f18;
    char pad3[3];
    int field;
};
class Method3 : public Function_1bf710 {
  public:
    Method3(int, int);
    virtual void Fn();
};
Method3::Method3(int a, int b) : Function_1bf710(a, 3) {
    field = b;
    f18 = ReadFlag(gOne);
    f10 = ReadFlag(gTwo);
    f11 = ReadFlag(gTwo);
    f12 = ReadFlag(gTwo);
}
