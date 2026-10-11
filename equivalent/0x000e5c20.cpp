// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 52/57, incomplete)
// FEDialog::vfunc_3 @ 0x000e5c20
int __cdecl FUN_000f6660(int value, int modulus);

class Element {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual char onKey(int key, int arg);
    virtual void e8();
    virtual void e9();
    virtual void onCancel(int flag);
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual char canFocus();
};

class FEDialog {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int key, int arg);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void setFocus(Element *e, int direction);
    char pad04[0x48 - 0x4];
    Element *focus;          // 0x48
    Element *children[0x80]; // 0x4c
    char pad24c[0x9a8 - 0x24c];
    char enabled;            // 0x9a8
};

char FEDialog::vfunc_3(int key, int arg)
{
    if (!enabled)
        return 0;
    if (focus) {
        if (focus->onKey(key, arg))
            return 1;
    }
    if (key == 8 || key == 0xb) {
        if (focus)
            focus->onCancel(0);
    }

    int cur = 0;
    if (key == 0 || key == 4 || key == 2 || key == 6) {
        for (int i = 0; i < 0x80; i++) {
            Element *c = children[i];
            if (c && c->canFocus() && children[i] == focus) {
                cur = i;
                break;
            }
        }
    }

    switch (key) {
    case 0:
    case 6: {
        int i = FUN_000f6660(cur - 1, 0x80);
        while (i != cur) {
            Element *c = children[i];
            if (c && c->canFocus()) {
                setFocus(children[i], 1);
                return 1;
            }
            i = FUN_000f6660(i - 1, 0x80);
        }
        setFocus(children[cur], 1);
        return 1;
    }
    case 2:
    case 4: {
        int i = (cur + 1) % 0x80;
        while (i != cur) {
            Element *c = children[i];
            if (c && c->canFocus()) {
                setFocus(children[i], 2);
                return 1;
            }
            i = (i + 1) % 0x80;
        }
        setFocus(children[cur], 2);
        return 1;
    }
    default:
        return 0;
    }
}
