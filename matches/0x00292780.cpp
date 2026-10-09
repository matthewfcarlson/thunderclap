namespace pure3d {
class Camera {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void vfunc_6(unsigned int*, unsigned int*);
    char pad[0x0c];
    unsigned int x;
    unsigned int y;
};
void Camera::vfunc_6(unsigned int* a, unsigned int* b) {
    *a = x;
    *b = y;
}
} // namespace pure3d