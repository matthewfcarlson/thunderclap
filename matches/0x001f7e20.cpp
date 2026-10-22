extern char name1[];
extern char name2[];
extern unsigned char __cdecl find(char*);
class Function_1f7e20 {
  public:
    Function_1f7e20(char*, int);
    virtual void f();
};
class Method1 : public Function_1f7e20 {
  public:
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    unsigned int x;
    Method1(char* p, unsigned int n) : Function_1f7e20(p, 1) {
        x = n;
        b = find(name1);
        a = find(name2);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    unsigned int y;
    Closure1(char* p, unsigned int n, unsigned int m);
    virtual void f();
};
Closure1::Closure1(char* p, unsigned int n, unsigned int m) : Method1(p, m) {
    y = n;
}
