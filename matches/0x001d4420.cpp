// Same code shape as 0x00106cc0 (propagated; names are from that function)
class Closure1 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2(void*, const char**, bool*);
    char pad[0x18];
    typedef bool(__fastcall* Fn)(void*, const char*, const char*);
    Fn mFn;
    void* mObj;
};
void Closure1::V2(void* a, const char** p, bool* out) {
    void* obj = mObj;
    Fn fn = mFn;
    bool r = fn(obj, *p, *p);
    if (out)
        *out = r;
}