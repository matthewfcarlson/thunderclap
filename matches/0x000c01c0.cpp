class CFEManager {
  public:
    void method(const char*, const char*, const char*, const char*, const char*, const char*);
};
class Closure6 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(void*, const char**, void*);
    char pad[0x18];
    void (CFEManager::*fn)(const char*, const char*, const char*, const char*, const char*, const char*);
    CFEManager* obj;
};
inline const char* take(const char**& p) {
    return *p++;
}
void Closure6::vfunc_2(void*, const char** a, void*) {
    const char* t0 = take(a);
    const char* t1 = take(a);
    const char* t2 = take(a);
    const char* t3 = take(a);
    const char* t4 = take(a);
    const char* t5 = take(a);
    (obj->*fn)(t0, t1, t2, t3, t4, t5);
}