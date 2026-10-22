extern "C" unsigned char __cdecl Check(const char*);
extern char key1[];
extern char key2[];
class Function_202fa0 {
  public:
    Function_202fa0(int, int);
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
};
class Method1 : public Function_202fa0 {
  public:
    Method1(int p, int x) : Function_202fa0(p, 1) {
        this->x = x;
        b = Check(key1);
        a = Check(key2);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(int p, int y, int x);
    virtual void f();
    int y;
};
Closure1::Closure1(int p, int y, int x) : Method1(p, x) {
    this->y = y;
}