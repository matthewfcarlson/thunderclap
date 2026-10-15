namespace pure3d {
struct V3 {
    int x, y, z;
};
struct V2 {
    int x, y;
};
class d3dPrimBufferStream {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(const V3*, int, const V2*);
    void advance();
    char pad[0x20];
    V3* xyz;
    char pad2[8];
    int* color;
    char pad3[4];
    V2* uv;
};
void d3dPrimBufferStream::vfunc_13(const V3* p, int c, const V2* t) {
    V3* dest = xyz;
    dest->x = p->x;
    dest->y = p->y;
    dest->z = p->z;
    *color = c;
    *uv = *t;
    advance();
}
} // namespace pure3d