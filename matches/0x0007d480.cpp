class type_info {
  public:
    virtual ~type_info();
};
extern int g_vftable;
extern "C" unsigned char __cdecl FUN_001d04d0(const type_info&);
class Method3 {
  public:
    int vptr;
    char pad04[0x0c];
    unsigned char a10, a11, a12;
    char pad13[5];
    unsigned char a18;
    char pad19[3];
    void* owner;
    void Init(const char*, int);
    Method3* Build(const char*, void*);
};
Method3* Method3::Build(const char* name, void* mgr) {
    Init(name, 3);
    *(void**)this = &g_vftable;
    owner = mgr;
    a18 = FUN_001d04d0(typeid(void));
    a10 = FUN_001d04d0(typeid(const char*));
    a11 = FUN_001d04d0(typeid(unsigned int));
    a12 = FUN_001d04d0(typeid(float));
    return this;
}
