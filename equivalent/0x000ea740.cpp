// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// TextSelector::vfunc_7 @ 0x000ea740
struct Chooser_ea740 {
    bool FUN_000f92b0(int lo, int hi, char* out);
};

// The incoming argument slot doubles as the output byte of the lookup.
union ChooserArg {
    Chooser_ea740* chooser;
    char picked;
};

struct Listener_ea740 {
    void FUN_000f8b90(int index);
};

class TextSelector {
public:
    virtual void Refresh();     // slot 0
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7(ChooserArg arg);
    char pad04[0x90 - 4];
    int idLo;               // 0x90
    int idHi;               // 0x94
    char pad98[0x150 - 0x98];
    int defaultIndex;       // 0x150
    int index;              // 0x154
    char pad158[0x1d58 - 0x158];
    int count;              // 0x1d58
    char pad1d5c[0x1d94 - 0x1d5c];
    Listener_ea740* listener;     // 0x1d94
};

void TextSelector::vfunc_7(ChooserArg arg)
{
    if ((idLo | idHi) == 0)
        return;
    int newIndex;
    if (arg.chooser->FUN_000f92b0(idLo, idHi, &arg.picked)) {
        int sel = arg.picked;
        int last = count - 1;
        if (sel > last)
            newIndex = last;
        else if (sel < 0)
            newIndex = 0;
        else
            newIndex = sel;
    } else {
        newIndex = defaultIndex;
    }
    index = newIndex;
    if (listener != 0)
        listener->FUN_000f8b90(newIndex);
    Refresh();
}
