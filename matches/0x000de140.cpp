typedef unsigned char u8;
class ControllerPollerBase {
public:
    virtual void f();
    int a;
    void* p;
    u8 c[4];
    int d;
    ControllerPollerBase(void*);
};
extern u8 g;
ControllerPollerBase::ControllerPollerBase(void* x) {
    p = x;
    a = 0;
    g = 0;
    d = 0;
    c[0] = 0;
}