class Root {
  public:
    Root(const char*, int);
    virtual void f();
    char pad[12];
    char a;
    char p1[7];
    char b;
    char p2[3];
    int x;
};
extern int check(const char*);
extern const char tag1[];
extern const char tag2[];
class Method1 : public Root {
  public:
    Method1(const char*, int, int);
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char*, int, int);
    virtual void f();
    int y;
};
Method1::Method1(const char* s, int x0, int x1) : Root(s, 1) {
    x = x1;
    b = check(tag1);
    a = check(tag2);
}
Closure1::Closure1(const char* s, int x0, int x1) : Method1(s, x0, x1) {
    y = x0;
}