// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// pure3d::TextString::vfunc_6 @ 0x0029b210
// 0x0029b210: TextString::vfunc_6: draw the string through its font object, wrapping a scale if set
#include "gen/pure3d.h"

#include "decls/data/engine/pure3d/prop.h"

struct Font_29b210 {
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

struct Context_29b210 {
    Device_29b210* device;
    void FUN_00293da0(int a, int b, int c);
};

void pure3d::TextString::vfunc_6() {
    int saved = (int)this;
    if (this->f_4c != 0x3f800000) {
        (*(Context_29b210**)&DAT_0052c2ac)->device->PushState(0);
        (*(Context_29b210**)&DAT_0052c2ac)->FUN_00293da0(this->f_4c, this->f_4c, 0x3f800000);
    }
    (*(Font_29b210 * *)&this->f_40)->GetColour(&saved);
    (*(Font_29b210 * *)&this->f_40)->SetColour(this->f_44);
    (*(Font_29b210 * *)&this->f_40)->SetLayout(this->f_48, 0);
    (*(Font_29b210 * *)&this->f_40)->SetColour(saved);
    if (this->f_4c != 0x3f800000)
        (*(Context_29b210**)&DAT_0052c2ac)->device->PopState(0);
}
