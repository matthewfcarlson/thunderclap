extern "C" unsigned char ReadFlag(const char*);
extern const char gA[];
extern const char gB[];
class Parent {
  public:
    Parent(void*, int);
    virtual void v();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* p;
    void* q;
};
class Core : public Parent {
  public:
    Core(void* a, void* c) : Parent(a, 1) {
        p = c;
        y = ReadFlag(gA);
        x = ReadFlag(gB);
    }
    virtual void v();
};
class Closure : public Core {
  public:
    Closure(void*, void*, void*);
    virtual void v();
    virtual void v2();
};
Closure::Closure(void* a, void* b, void* c) : Core(a, c) {
    q = b;
}