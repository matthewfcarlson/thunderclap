class BinReader {
  public:
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
    virtual void vg();
    virtual void vh();
    virtual char vi(int, int, int, int);
    virtual void vj();
    virtual char vk(int, int, int);
    virtual void vl();
    virtual void vm();
    virtual void vn();
    virtual void vo();
    virtual void vp();
    virtual void vq();
    virtual void vr();
    virtual void vs();
    virtual void vt();
    char pad[8];
    unsigned char mode;
    char vfunc_6(int, int, int, int, int);
};
char BinReader::vfunc_6(int p2, int p3, int p4, int p5, int p6) {
    if (mode)
        return vk(p2, p3, p4);
    else
        return vi(p2, p3, p5, p6);
}