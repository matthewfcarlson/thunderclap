// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// pure3d::TextString::vfunc_6 @ 0x0029b210
// 0x0029b210: TextString::vfunc_6: draw the string through its font object, wrapping a scale if set
#include "decls/data/engine/pure3d/prop.h"

struct Font {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual void SetLayout(int a, int b);
    virtual void v12(); virtual void v13();
    virtual void GetColour(int* out);
    virtual void SetColour(int c);
};

struct Device_29b210 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void PushState(int a);
    virtual void PopState(int a);
};

struct Context {
    Device_29b210* device;
    void FUN_00293da0(int a, int b, int c);
};

class TextString {
public:
    char pad00[0x40];
    Font* font;
    int colour;
    int layout;
    int scale;
    void FUN_0029b210();
};

void TextString::FUN_0029b210()
{
    int saved = (int)this;
    if (scale != 0x3f800000) {
        (*(Context**)&DAT_0052c2ac)->device->PushState(0);
        (*(Context**)&DAT_0052c2ac)->FUN_00293da0(scale, scale, 0x3f800000);
    }
    font->GetColour(&saved);
    font->SetColour(colour);
    font->SetLayout(layout, 0);
    font->SetColour(saved);
    if (scale != 0x3f800000)
        (*(Context**)&DAT_0052c2ac)->device->PopState(0);
}
