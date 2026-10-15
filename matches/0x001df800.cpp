class Base {
  public:
    Base(const char*, int);
    virtual void a();
};
extern "C" unsigned char __cdecl F(const char*);
extern const char s1[], s2[];
class Method2 : public Base {
  public:
    char p0[12];
    unsigned char b10, b11;
    char p12[6];
    unsigned char b18;
    char p19[3];
    int x1c;
    virtual void a();
    Method2(const char*, int);
};
Method2::Method2(const char* s, int x) : Base(s, 2) {
    x1c = x;
    b18 = F(s1);
    b10 = F(s2);
    b11 = F(s1);
}