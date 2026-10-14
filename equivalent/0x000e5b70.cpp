// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 15/16, incomplete)
// FEDialog::vfunc_1 @ 0x000e5b70
class Widget {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int msg, int arg);
};

struct Button {
    char pad00[0x14];
    Widget *widget;         // 0x14
};

class FEDialog {
public:
    virtual void vfunc_0();
    virtual bool vfunc_1(int msg, int arg);
    char pad04[0x44];
    Widget *focus;          // 0x48
    char pad4c[0x998 - 0x4c];
    Button *button0;        // 0x998
    Button *button1;        // 0x99c
    Button *button2;        // 0x9a0
    char pad9a4[4];
    char active;            // 0x9a8
    char pad9a9[3];
    int selected;           // 0x9ac
};

bool FEDialog::vfunc_1(int msg, int arg)
{
    if (!active)
        return false;

    Widget *w = focus;
    if (w == 0)
        return false;

    if (msg == 8 || msg == 0xb) {
        if (w == button0->widget)
            selected = 0;
        else if (w == button1->widget)
            selected = 1;
        else if (w == button2->widget)
            selected = 2;
    }
    return w->vfunc_5(msg, arg);
}
