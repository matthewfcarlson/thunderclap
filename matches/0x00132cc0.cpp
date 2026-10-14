extern "C" char DAT_00411344[];
class DialogueTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    int a, b, c, d, e, f;
    char g;
    void Init();
};
void* __cdecl FUN_0008d690(unsigned int);
class Factory_132cc0 {
  public:
    void* Create();
};
void* Factory_132cc0::Create() {
    DialogueTrack* p = (DialogueTrack*)FUN_0008d690(0x28);
    int z = 0;
    if (p != 0) {
        p->Init();
        p->a = z;
        p->b = z;
        p->c = z;
        p->d = z;
        p->e = z;
        p->f = z;
        p->g = (char)z;
        *(void**)p = (void*)((int)DAT_00411344);
        *((int*)p + 2) = 1;
        return p;
    }
    return 0;
}
