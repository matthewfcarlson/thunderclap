extern "C" char DAT_0042de4c[];
class TextureAnimationController {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual TextureAnimationController* V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    void Init(TextureAnimationController*);
    char pad[60];
    TextureAnimationController* mRef;
};
extern void* __cdecl Alloc(unsigned int);
TextureAnimationController* TextureAnimationController::V4() {
    TextureAnimationController* p = (TextureAnimationController*)Alloc(0x48);
    if (p) {
        p->Init(this);
        *(unsigned int*)p = ((int)DAT_0042de4c);
        p->mRef = 0;
        TextureAnimationController* r = mRef;
        if (r)
            r->V0();
        if (p->mRef)
            p->mRef->V1();
        p->mRef = r;
    } else {
        return 0;
    }
    return p;
}