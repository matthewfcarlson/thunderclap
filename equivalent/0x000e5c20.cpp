// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 52/57, incomplete)
// FEDialog::vfunc_3 @ 0x000e5c20
#include "gen/global.h"

int __cdecl FUN_000f6660(int value, int modulus);

class Element_e5c20 {
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

bool FEDialog::vfunc_3(int key, int arg) {
    if (!(*(char *)&this->f_9a8))
        return (bool)(0);
    if ((*(Element_e5c20 * *)&this->f_48)) {
        if ((*(Element_e5c20 * *)&this->f_48)->onKey(key, arg))
            return (bool)(1);
    }
    if (key == 8 || key == 0xb) {
        if ((*(Element_e5c20 * *)&this->f_48))
            (*(Element_e5c20 * *)&this->f_48)->onCancel(0);
    }

    int cur = 0;
    if (key == 0 || key == 4 || key == 2 || key == 6) {
        for (int i = 0; i < 0x80; i++) {
            Element_e5c20 *c = (*(Element_e5c20 * (*)[128])&this->f_4c)[i];
            if (c && c->canFocus() && (*(Element_e5c20 * (*)[128])&this->f_4c)[i] == (*(Element_e5c20 * *)&this->f_48)) {
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
            Element_e5c20 *c = (*(Element_e5c20 * (*)[128])&this->f_4c)[i];
            if (c && c->canFocus()) {
                vfunc_52((*(Element_e5c20 * (*)[128])&this->f_4c)[i], 1);
                return (bool)(1);
            }
            i = FUN_000f6660(i - 1, 0x80);
        }
        vfunc_52((*(Element_e5c20 * (*)[128])&this->f_4c)[cur], 1);
        return (bool)(1);
    }
    case 2:
    case 4: {
        int i = (cur + 1) % 0x80;
        while (i != cur) {
            Element_e5c20 *c = (*(Element_e5c20 * (*)[128])&this->f_4c)[i];
            if (c && c->canFocus()) {
                vfunc_52((*(Element_e5c20 * (*)[128])&this->f_4c)[i], 2);
                return (bool)(1);
            }
            i = (i + 1) % 0x80;
        }
        vfunc_52((*(Element_e5c20 * (*)[128])&this->f_4c)[cur], 2);
        return (bool)(1);
    }
    default:
        return (bool)(0);
    }
}
