class Image32 {
  public:
    char pad0[0x10];
    int mWidth;
    char pad14[0x10];
    unsigned int* mPixels;
    unsigned int vfunc_9(int x, int y);
};
unsigned int Image32::vfunc_9(int x, int y) {
    return mPixels[mWidth * y + x];
}