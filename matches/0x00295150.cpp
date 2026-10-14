class Font {
    char pad[0x20];
};
class TextureFont : public Font {
  public:
    void vfunc_13(float);
};
extern const float zero_295150;
void TextureFont::vfunc_13(float x) {
    if (x > 0.0f)
        *(float*)((char*)this + 0x20) = x;
    else
        *(int*)((char*)this + 0x20) = 0;
}