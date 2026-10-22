class Function_1ce200 {
  public:
    virtual void Invoke(float);
    Function_1ce200(void*, int);
};
extern "C" unsigned char __cdecl Check(const char*);
extern const char a[];
extern const char b[];
class Method1 : public Function_1ce200 {
  public:
    virtual void Invoke(float);
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* obj;
    Method1(void* p, void* q) : Function_1ce200(p, 1) {
        obj = q;
        y = Check(a);
        x = Check(b);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    void* fn;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* p, void* q, void* r) : Method1(p, r) {
    fn = q;
}