namespace pure3d {
struct ImageData {
    char pad[8];
    unsigned int width;
    unsigned int height;
};
struct ImageLoader {
    char pad[0x18];
    unsigned int imageFormat;
    ImageData* FUN_002c0590(unsigned int data, unsigned int format);
    void vfunc_5(ImageData** image, unsigned int* size, unsigned int data, unsigned int unused);
};
} // namespace pure3d
void pure3d::ImageLoader::vfunc_5(ImageData** image, unsigned int* size, unsigned int data,
                                  unsigned int unused) {
    ImageData* loaded = FUN_002c0590(data, imageFormat);
    if (loaded) {
        *image = loaded;
        size[0] = loaded->width;
        size[1] = loaded->height;
    }
}