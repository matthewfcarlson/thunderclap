class ImageHandler {
  public:
    class Builder {
      public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
    };
};
class TextureBuilder_2ae890 : public ImageHandler::Builder {
  public:
    char pad[8];
    void* mPtr;
    unsigned int vfunc_5();
};
unsigned int TextureBuilder_2ae890::vfunc_5() {
    return *(unsigned int*)((char*)mPtr + 0x54);
}