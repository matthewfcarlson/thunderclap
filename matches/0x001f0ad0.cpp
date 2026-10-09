// Same code shape as 0x000beac0 (propagated; names are from that function)
class CFEManager {
  public:
    void Call(const char*, int);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method2 : public Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(void*, void*, int);
    char pad[0x1c - 4];
    void (CFEManager::*fn)(const char*, int);
};
void Method2::vfunc_2(void* unused, void* p, int n) {
    CFEManager* m = (CFEManager*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*fn)(s, x);
}