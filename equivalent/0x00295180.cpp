// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// pure3d::TextureFont::vfunc_14 @ 0x00295180
namespace pure3d {
struct TextureFont {
    char padding[0x24];
    int value;
    void vfunc_14(int *output);
};
void TextureFont::vfunc_14(int *output) {
    *output = value;
}
}