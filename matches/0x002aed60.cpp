// cl-flags: /O2 /GR /GX
extern "C" char DAT_0042e184[];

class ImageBuilder {
  public:
    virtual ~ImageBuilder() {}
    virtual void V1() {}
    virtual void V2() {}
    virtual void V3() {}
    virtual void V4() {}
    virtual void V5() {}
    virtual void V6() {}
    virtual void V7() {}
    virtual void V8() {}
};

class Iface_2aed60 {
  public:
    virtual ~Iface_2aed60() {}
    virtual void V0() {}
    virtual void V1() {}
    virtual void V2() {}
    virtual void V3() {}
    virtual void V4() {}
    virtual void V5() {}
    virtual void V6() {}
    virtual void V7() {}
    virtual void Process(void* param2, ImageBuilder* builder) {}
};

struct ThisCall_002ae9d0 {
    Iface_2aed60* FUN_002ae9d0(void* param);
};

class SomeClass {
  public:
    char pad[0x8C];
    int field_8C;

    int Method(void* param2, void* param3);
};

int SomeClass::Method(void* param2, void* param3) {
    Iface_2aed60* iface = ((ThisCall_002ae9d0*)(this))->FUN_002ae9d0(param3);
    if (!iface)
        return 0;

    struct ParamBlock {
        void* vptr;
        int zero1;
        int zero2;
        int zero3;
        int zero4;
        int zero5;
        int field_8C;
    } pb;

    pb.zero1 = 0;
    pb.zero2 = 0;
    pb.zero3 = 0;
    pb.zero4 = 0;
    pb.zero5 = 0;
    pb.field_8C = this->field_8C;

    // Direct immediate assignment to match target's mov [esp+8], 0x42e184
    pb.vptr = (void*)((int)DAT_0042e184);

    iface->Process(param2, (ImageBuilder*)&pb.vptr);

    return pb.zero1;
}