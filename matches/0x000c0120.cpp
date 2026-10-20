struct CFEManager {
    void Do(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
};
struct Args {
    const char* values[7];
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
};
class Closure7 : public Function {
  public:
    char pad[0x18];
    void (CFEManager::*f_1c)(const char*, const char*, const char*, const char*, const char*, const char*,
                             const char*);
    CFEManager* f_20;
    virtual void vfunc_2(void*, void*, void*);
};
void Closure7::vfunc_2(void* p0, void* p1, void* p2) {
    Args* args = (Args*)p1;
    const char** a = args->values;
    const char* v0 = *a++;
    const char* v1 = *a++;
    const char* v2 = *a++;
    const char* v3 = *a++;
    const char* v4 = *a++;
    const char* v5 = *a++;
    const char* v6 = *a++;
    (f_20->*f_1c)(v0, v1, v2, v3, v4, v5, v6);
}