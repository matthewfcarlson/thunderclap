class CCameraManager {
  public:
    void Fn(char*, char*, char*, char*);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
inline char* next(char**& p) {
    return *p++;
}
class Method4 : public Function {
  public:
    virtual void f0();
    virtual void vfunc_2(CCameraManager*, char**, void*);
    char pad[24];
    void (CCameraManager::*fn)(char*, char*, char*, char*);
};
void Method4::vfunc_2(CCameraManager* obj, char** args, void*) {
    char* a = next(args);
    char* b = next(args);
    char* c = next(args);
    char* d = next(args);
    (obj->*fn)(a, b, c, d);
}