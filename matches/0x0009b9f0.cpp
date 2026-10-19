extern "C" char hulk_at_0048e128[];
class Base {
  public:
    Base(int, int);
    virtual void f();
};
class Camera : public Base {
  public:
    Camera(int, int);
    virtual void f();
    char pad[0x14];
    unsigned char flag;
    char pad2[3];
    int value;
};
unsigned char __cdecl fun2(int);
Camera::Camera(int a, int b) : Base(a, 0) {
    value = b;
    flag = fun2(((int)hulk_at_0048e128));
}