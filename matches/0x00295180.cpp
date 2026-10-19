namespace pure3d {
struct TextureFont {
    char padding[0x24];
    int value;
    int* vfunc_14(int* output);
};
int* TextureFont::vfunc_14(int* output) {
    *output = value;
    return output;
}
} // namespace pure3d