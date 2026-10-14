// STATUS: equivalent (tools/equiv.py level 3: 2781 inputs, branch coverage 18/18)
// pure3d::ImageFont::vfunc_11 @ 0x002bf2a0
class Canvas {
public:
    virtual void begin();
    virtual void end();
};

namespace pure3d {
class ImageFont {
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
    virtual unsigned int vfunc_9(const unsigned short *text);
    virtual void v10();
    virtual void vfunc_11(Canvas *canvas, int a2, int y, const unsigned short *text, unsigned int flags);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void vfunc_17(Canvas *canvas, int a2, int y, const unsigned short *text, unsigned int flags);
    char pad04[0x18 - 4];
    int f18;
    char pad1c[4];
    int f20;
};
}

void pure3d::ImageFont::vfunc_11(Canvas *canvas, int a2, int y, const unsigned short *text, unsigned int flags)
{
    if (text == 0)
        return;
    if (canvas == 0)
        return;
    canvas->begin();
    int lineHeight = f20 + f18;
    unsigned int half = 0;
    if (flags & 2)
        half = vfunc_9(text) >> 1;
    y -= half;
    int i = 0;
    if (text[0] != 0) {
        do {
            vfunc_17(canvas, a2, y, text, flags);
            while (text[i] != 0 && text[i] != 10)
                i++;
            if (text[i] == 10)
                i++;
            y += lineHeight;
        } while (text[i] != 0);
    }
    canvas->end();
}
