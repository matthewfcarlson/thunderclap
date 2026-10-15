extern "C" void __stdcall Init(void*, int);
extern "C" unsigned char Check(const void*);
extern char gA[];
extern char gB[];
class Root {
  public:
    Root(void* p) { Init(p, 1); }
};
class Method1 : public Root {
  public:
    virtual void invoke(float);
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
    Method1(void* p, int v) : Root(p) {
        x = v;
        b = Check(gB);
        a = Check(gA);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke(float);
    int y;
    Closure1(void* p, int w, int v);
};
Closure1::Closure1(void* p, int w, int v) : Method1(p, v) {
    y = w;
}
