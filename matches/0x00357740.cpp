struct V {
    int x, y, z;
};
struct T {
    V a;
    int f[9];
    V b;
    T* Set(const V* pa, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11,
           const V* pb);
};
T* T::Set(const V* pa, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11,
          const V* pb) {
    a = *pa;
    b = *pb;
    f[0] = p3;
    f[1] = p4;
    f[2] = p5;
    f[3] = p6;
    f[4] = p7;
    f[5] = p8;
    f[6] = p9;
    f[7] = p10;
    f[8] = p11;
    return this;
}
