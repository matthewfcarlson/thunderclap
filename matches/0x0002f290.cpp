extern char str1[];
extern char str2[];
extern char __cdecl lookup(const char*);
class Function_2f290 {
  public:
    virtual void f();
    char pad[12];
    Function_2f290(const char*, int);
};
class Method1_2f290 : public Function_2f290 {
  public:
    virtual void f();
    char a;
    char pad1[7];
    char b;
    char pad2[3];
    int c;
    Method1_2f290(const char* s, int x) : Function_2f290(s, 1) {
        c = x;
        b = lookup(str1);
        a = lookup(str2);
    }
};
class Closure1_2f290 : public Method1_2f290 {
  public:
    virtual void f();
    int d;
    Closure1_2f290(const char*, int, int);
};
Closure1_2f290::Closure1_2f290(const char* s, int x, int y) : Method1_2f290(s, y) {
    d = x;
}
