extern "C" char DAT_0042e1b4[];
typedef unsigned int u32_2af0c0;
struct Manager_2af0c0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32_2af0c0 getA();
    virtual u32_2af0c0 getB();
};
extern Manager_2af0c0* gManager_2af0c0;
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
    *(volatile u32_2af0c0*)this = ((int)DAT_0042e1b4);
    c = 0;
    flag = 0;
    d = gManager_2af0c0->getB();
    e = gManager_2af0c0->getA();
}