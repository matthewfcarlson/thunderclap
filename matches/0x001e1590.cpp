extern "C" unsigned char __cdecl check(const void*);
extern char a[], b[];
class Function_1e1590 {
  public:
    virtual void run();
    char pad[0x0c];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    int id;
    Function_1e1590(const char*, int);
};
class Method1 : public Function_1e1590 {
  public:
    virtual void run();
    Method1(const char* name, int key) : Function_1e1590(name, 1) {
        id = key;
        y = check(a);
        x = check(b);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void run();
    int arg;
    Closure1(const char*, int, int);
};
Closure1::Closure1(const char* name, int value, int key) : Method1(name, key) {
    arg = value;
}
