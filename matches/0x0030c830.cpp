class Obj_30c830 {
  public:
    char pad[0xf8];
    unsigned char b;
    unsigned int w0, w1, w2, w3, w4, w5, w6, w7, w8;
    void CopyBase(const Obj_30c830&);
    Obj_30c830& Copy(const Obj_30c830&);
};
Obj_30c830& Obj_30c830::Copy(const Obj_30c830& src) {
    CopyBase(src);
    b = src.b;
    w0 = src.w0;
    w1 = src.w1;
    w2 = src.w2;
    w3 = src.w3;
    w4 = src.w4;
    w5 = src.w5;
    w6 = src.w6;
    w7 = src.w7;
    w8 = src.w8;
    return *this;
}