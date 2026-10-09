class ImageHandler {
  public:
    class Builder {
      public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void vfunc_7();
        virtual void vfunc_8();
    };
};
class TextureBuilder : public ImageHandler::Builder {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void vfunc_9();
    virtual void vfunc_10();
    void* mThing;
    char pad[0x14];
    void* mArg;
};
class Receiver {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14(void*);
};
void TextureBuilder::vfunc_10() {
    if (mThing) {
        Receiver* r = *(Receiver**)((char*)mThing + 0x10);
        r->v14(mArg);
    }
}