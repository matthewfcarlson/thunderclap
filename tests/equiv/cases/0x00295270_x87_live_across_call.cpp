struct Glyph {
    char pad0[0xc];
    float advance;
    char pad10[0x28 - 0x10];
};
namespace pure3d {
class TextureFont {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual float vfunc_18(const unsigned short* text);
    char pad04[0x34 - 4];
    int defaultGlyph;
    char pad38[4];
    Glyph* glyphs;
    int FUN_00294ed0(unsigned int ch);
};
float TextureFont::vfunc_18(const unsigned short* text) {
    if (text == 0)
        return 0.0f;
    unsigned short ch = *text;
    if (ch == 0 || ch == 10)
        return 0.0f;
    float width = 0.0f;
    while (ch != 10) {
        int idx = FUN_00294ed0(ch);
        if (idx >= 0)
            width += glyphs[idx].advance;
        else
            width += glyphs[defaultGlyph].advance;
        text++;
        ch = *text;
        if (ch == 0)
            break;
    }
    return width;
}
}
