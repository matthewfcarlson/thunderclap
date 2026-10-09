class Image32 { public: char pad0[0x10]; int mWidth; int mHeight; char pad18[0x24-0x18]; unsigned int *mPixels; void vfunc_11(unsigned int); };
void Image32::vfunc_11(unsigned int value) {
    unsigned int *p = mPixels;
    int count = mHeight * mWidth;
    int i = 0;
    if (count > 0) {
        do {
            *p++ = value;
            ++i;
            count = mHeight * mWidth;
        } while (i < count);
    }
}