class CActorManager {
  public:
    int Do(const char*);
    inline int Invoke(int (CActorManager::*f)(const char*), const char* p) { return (this->*f)(p); }
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CActorManager*, const char**, int*);
};
class Method1 : public Function {
  public:
    char pad[0x18];
    int (CActorManager::*fn)(const char*);
    virtual void v2(CActorManager*, const char**, int*);
};
void Method1::v2(CActorManager* arg, const char** value, int* out) {
    int (CActorManager::*f)(const char*) = fn;
    int r = arg->Invoke(f, *value);
    if (out)
        *out = r;
}