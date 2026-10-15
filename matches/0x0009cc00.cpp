extern float gFloat;
extern "C" unsigned char __cdecl Check(const float*);
class Root {
  public:
    Root(void*, int);
    virtual void Invoke();
};
class Method0 : public Root {
  public:
    Method0(void* p, void* q) : Root(p, 0) {
        first = q;
        flag = Check(&gFloat);
    }
    virtual void Invoke();
    char pad[20];
    unsigned char flag;
    char pad2[3];
    void* first;
};
class Closure0 : public Method0 {
  public:
    Closure0(void* p, void* v, void* q);
    virtual void Invoke();
    void* second;
};
Closure0::Closure0(void* p, void* v, void* q) : Method0(p, q) {
    second = v;
}