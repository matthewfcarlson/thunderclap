extern char name1[];
extern char name2[];
extern unsigned char __cdecl find(char*);
class Parent {
  public:
    Parent(char*, int);
    virtual void f();
};
class Method1 : public Parent {
  public:
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    unsigned int x;
    Method1(char* p, unsigned int n) : Parent(p, 1) {
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
