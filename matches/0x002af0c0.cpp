typedef unsigned int u32;
struct Manager {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 getA();
    virtual u32 getB();
};
extern Manager* gManager;
class ImageHandler {
  public:
    int a;
    int b;
    int c;
    unsigned char flag;
    int d;
    int e;
    ImageHandler();
};
ImageHandler::ImageHandler() {
    b = 0;
    *(volatile u32*)this = 0x42e1b4;
    c = 0;
    flag = 0;
    d = gManager->getB();
    e = gManager->getA();
}