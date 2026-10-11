// STATUS: equivalent (tools/equiv.py level 3: 171 inputs, branch coverage 51/62, incomplete)
// FEMenuBase::vfunc_3 @ 0x000e6050
class Widget {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(int a1, int a2);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual char v7(int a1, int a2);
    virtual void v8();
    virtual void v9();
    virtual void v10(int x);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual char v19();
};

class Ref {
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48(int x);
};

int __cdecl FUN_000f6660(int a, int b);

class FEMenuBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char vfunc_3(int a1, int a2);
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52(Widget *w, int mode);
    Ref *ref;
    char pad8[0x40];
    Widget *current;
    Widget *items[0x80];
    char pad24c[0x854 - 0x24c];
    int owner;
    char pad858[0xab8 - 0x858];
    char active;
    char padab9[3];
    Widget *children[0x20];
    int childCount;

    void FUN_000e4ec0(int x);
};

char FEMenuBase::vfunc_3(int a1, int a2)
{
    if (!active)
        return 0;
    if (owner != -1 && owner != a2)
        return 0;
    for (int i = 0; i < childCount; i++) {
        if (children[i]->v3(a1, a2))
            break;
    }
    if (a1 == 8) {
        if (!current)
            return 0;
        current->v10(0);
        ref->v48(0);
        return 1;
    }
    if (a1 == 0xb)
        FUN_000e4ec0(5);
    if (!current)
        return 0;
    if (current->v7(a1, a2))
        return 1;
    int sel = 0;
    if (a1 == 0 || a1 == 4) {
        for (int i = 0; i < 0x80; i++) {
            if (items[i] && items[i]->v19() && items[i] == current) {
                sel = i;
                break;
            }
        }
    }
    if (a1 == 0) {
        int i = FUN_000f6660(sel - 1, 0x80);
        while (i != sel) {
            if (items[i] && items[i]->v19()) {
                v52(items[i], 1);
                if (i != sel)
                    return 1;
                break;
            }
            i = FUN_000f6660(i - 1, 0x80);
        }
        v52(items[sel], 1);
        return 1;
    }
    if (a1 == 4) {
        int i = (sel + 1) % 0x80;
        if (i != sel) {
            while (i != sel) {
                if (items[i] && items[i]->v19()) {
                    v52(items[i], 2);
                    if (i != sel)
                        return 1;
                    break;
                }
                i = (i + 1) % 0x80;
            }
        }
        v52(items[sel], 2);
        return 1;
    }
    return 0;
}
