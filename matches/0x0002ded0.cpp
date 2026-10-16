class CActorManager {
  public:
    int Run(const char*, const char*);
};
struct Function {
    virtual void f0();
    virtual void f1();
    virtual void f2(CActorManager*, const char**, int*);
};
class Method2 : public Function {
  public:
    char pad[0x18];
    int (CActorManager::*fn)(const char*, const char*);
    virtual void f2(CActorManager*, const char**, int*);
};
void Method2::f2(CActorManager* a, const char** b, int* out) {
    int (CActorManager::*f)(const char*, const char*) = fn;
    const char* x = b[0];
    const char* y = b[1];
    int r = (a->*f)(x, y);
    if (out)
        *out = r;
}
