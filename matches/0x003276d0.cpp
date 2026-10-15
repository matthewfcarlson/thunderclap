namespace pure3d {
struct V3 {
    int a, b, c;
};
struct V2 {
    int a, b;
};
inline void Copy3(V3* dst, const V3* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}
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
    virtual void vfunc_13();
    virtual void vfunc_14(const V3*, const V2*);
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    char pad[0x20];
    V3* pos;
    char pad2[0x10];
    V2* tex;
    void Advance();
};
void d3dPrimBufferStream::vfunc_14(const V3* p, const V2* t) {
    Copy3(pos, p);
    *tex = *t;
    Advance();
}
} // namespace pure3d