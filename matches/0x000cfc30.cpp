extern char gA[];
extern char gB[];
extern "C" char Get(char const*);
class Root {
  public:
    Root(int, int);
    virtual void f();
    char pad[12];
};
class Method2 : public Root {
  public:
    Method2(int a, int c);
    virtual void f();
    char x;
    char y;
    char pad2[6];
    char z;
    char pad3[3];
    int value;
};
class Closure2 : public Method2 {
  public:
    Closure2(int a, int b, int c);
    virtual void f();
    int other;
};
inline Method2::Method2(int a, int c) : Root(a, 2) {
    value = c;
    z = Get(gA);
    x = Get(gA);
    y = Get(gB);
}
Closure2::Closure2(int a, int b, int c) : Method2(a, c) {
    other = b;
}
