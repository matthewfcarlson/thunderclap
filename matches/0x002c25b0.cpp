void* operator new(unsigned n) throw();
class A_2c25b0 {
  public:
    A_2c25b0() throw();
    char p[0xa4];
};
class ImageConverter_2c25b0 {
  public:
    ImageConverter_2c25b0() throw();
    char p[4];
};
class SimpleChunkHandler_2c25b0 {
  public:
    SimpleChunkHandler_2c25b0() {
        m4 = 0;
        m8 = 0x19000;
        mc = 0;
        m10 = 0;
    }
    virtual void f0();
    int m4, m8, mc, m10;
};
class TextureLoader : public SimpleChunkHandler_2c25b0 {
  public:
    TextureLoader();
    virtual void f0();
    A_2c25b0* m14;
    ImageConverter_2c25b0* m18;
};
TextureLoader::TextureLoader() {
    m14 = new A_2c25b0;
    m18 = new ImageConverter_2c25b0;
}
