class ImageFont {
  public:
    char pad[0x20];
    unsigned int value;
    void vfunc_13(unsigned int);
};
void ImageFont::vfunc_13(unsigned int x) {
    value = (x > 0U ? 0xffffffffU : 0U) & x;
}