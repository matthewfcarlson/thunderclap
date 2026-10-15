extern "C" unsigned char getFlag(void*);
extern int gValue;
class Root {
  public:
    Root(int, int);
    virtual void fn();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
    int y;
};
class Method1 : public Root {
  public:
    Method1(int p, int q) : Root(p, 1) {
        x = q;
        b = getFlag(&gValue);
        a = getFlag(&gValue);
    }
    virtual void fn();
};
class Closure1 : public Method1 {
  public:
    Closure1(int p, int q, int r);
    virtual void fn();
};
Closure1::Closure1(int p, int q, int r) : Method1(p, r) {
    y = q;
}
