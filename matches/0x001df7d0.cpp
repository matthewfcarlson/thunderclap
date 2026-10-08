class CSPManager { public: bool invoke(const char*, int, int); };
struct Args { const char* a; int b; int c; };
class Method3 {
public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(CSPManager* obj, Args* args, bool* out);
    char pad[0x18];
    bool (CSPManager::*mFn)(const char*, int, int);
};
void Method3::vfunc_2(CSPManager* obj, Args* args, bool* out) {
    bool (CSPManager::*fn)(const char*, int, int) = mFn;
    const char* a = args->a;
    int b = args->b;
    int c = args->c;
    bool r = (obj->*fn)(a, b, c);
    if (out) *out = r;
}
