class type_info {
  public:
    virtual ~type_info();
};
extern int g_vftable_90840;
extern "C" unsigned char __cdecl FUN_001d04d0(const type_info&);
class Method6 {
  public:
    int vptr;
    char pad04[0x0c];
    unsigned char a10, a11, a12, a13, a14, a15, a16, a17, a18;
    char pad19[3];
    void* owner;
    void Init(const char*, int);
    Method6* Build(const char*, void*);
};
Method6* Method6::Build(const char* name, void* mgr) {
    Init(name, 6);
    *(void**)this = &g_vftable_90840;
    owner = mgr;
    a18 = FUN_001d04d0(typeid(void));
    a10 = FUN_001d04d0(typeid(const char*));
    a11 = FUN_001d04d0(typeid(const char*));
    a12 = FUN_001d04d0(typeid(int));
    a13 = FUN_001d04d0(typeid(int));
    a14 = FUN_001d04d0(typeid(int));
    a15 = FUN_001d04d0(typeid(int));
    return this;
}
