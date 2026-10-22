// STATUS: equivalent (tools/equiv.py level 3: 20177 inputs, branch coverage 125/133, incomplete)
// FEScreenBase::vfunc_3 @ 0x000e5710
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" int memcmp(const void *, const void *, unsigned int);
// MSVC 7.1 expands memcmp against a string literal inline (repe cmpsb); so does this.
static inline int memcmp_lit(const char *a, const char *b, unsigned n)
{
    for (; n != 0; n--, a++, b++)
        if (*a != *b)
            return (unsigned char)*a - (unsigned char)*b;
    return 0;
}
int __cdecl FUN_000f6660(int value, int modulus);

class FELayout {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(int key, int arg);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual char v7(int key, int arg);
    virtual void v8();
    virtual void v9();
    virtual void v10(int flag);
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
class SingleLayout : public FELayout {
  public:
    virtual void v20();
    virtual void v21();
    virtual char v22();
};

class Child_e5710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(int key, int arg);
};

class Names_e5710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char *v8();
};

class Parent_e5710 {
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
    virtual void v16(const char *s);
    virtual void v17();
    virtual void v18(const char *s);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    char pad[0x175c - 4];
    Names_e5710 *names;
};

struct State_e5710 {
    char FUN_000b4f20();
    char FUN_000b8c90();
};
struct Sub_e5710 {
    State_e5710 *FUN_00086280();
    int *FUN_00086270();
};
struct World {
    char pad[0x54];
    Sub_e5710 *sub;
};

union Arg2_e5710 {
    int arg;
    char flag;
};

class FEScreenBase {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int key, Arg2_e5710 a2);
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
    virtual void setWidget(FELayout *w, int dir);
    Parent_e5710 *parent;
    char pad08[0x48 - 0x8];
    FELayout *focus;
    FELayout *widgets[0x80];
    char pad24c[0xa64 - 0x24c];
    char field_a64;
    char padA65[0xa78 - 0xa65];
    int field_a78;
    char padA7c[0xab8 - 0xa7c];
    char enabled;
    char padAB9[3];
    Child_e5710 *kids[0x20];
    int kidCount;
    char text_b40[0x40];
    char text_b80[0x40];
};

char FEScreenBase::vfunc_3(int key, Arg2_e5710 a2)
{
    if (!enabled)
        return 0;
    if (field_a78)
        return 0;
    for (int k = 0; k < kidCount; k++) {
        if (kids[k]->v3(key, a2.arg))
            break;
    }
    if (!field_a64) {
        if (key == 0xa) {
            if (focus)
                focus->v10(1);
            State_e5710 *s = DAT_004dd700->sub->FUN_00086280();
            if (!(s->FUN_000b4f20() && s->FUN_000b8c90()))
                parent->v21();
            return 1;
        }
        if (key == 0xb) {
            if (memcmp_lit(parent->names->v8(), "side_mission_fail", 0x12) != 0 &&
                memcmp_lit(parent->names->v8(), "story_mission_fail", 0x13) != 0 &&
                memcmp_lit(parent->names->v8(), "side_mission_success", 0x15) != 0 &&
                memcmp_lit(parent->names->v8(), "story_mission_success", 0x16) != 0 &&
                *DAT_004dd700->sub->FUN_00086270() == 6) {
                if (focus)
                    focus->v10(1);
                parent->v23();
                return 1;
            }
        }
    }
    if (focus) {
        if (focus->v7(key, a2.arg))
            return 1;
    }
    if (key == 0xa) {
        if (focus)
            focus->v10(1);
        parent->v21();
        return 1;
    }
    if (key == 0xc) {
        if (memcmp_lit(text_b40, "", 1) != 0) {
            parent->v16(text_b40);
            return 1;
        }
    } else if (key == 0xd) {
        if (memcmp_lit(text_b80, "", 1) != 0) {
            parent->v18(text_b80);
            return 1;
        }
    }
    if ((*(char*)&DAT_004de950)) {
        if (key == 8 && focus) {
            focus->v10(0);
            return 1;
        }
    } else if (key == 0xb || key == 8) {
        (*(char*)&DAT_004de950) = 1;
        if (focus) {
            focus->v10(0);
            return 1;
        }
    }

    int cur = 0;
    if (key == 0 || key == 4 || key == 2 || key == 6) {
        for (int i = 0; i < 0x80; i++) {
            FELayout *w = widgets[i];
            if (w && w->v19() && widgets[i] == focus) {
                cur = i;
                break;
            }
        }
    }

    switch (key) {
    case 0:
    case 6: {
        a2.flag = 0;
        if (widgets[cur]) {
            SingleLayout *sl = dynamic_cast<SingleLayout *>(widgets[cur]);
            if (sl)
                a2.flag = sl->v22();
        }
        if (key == 6) {
            if (!a2.flag)
                return 0;
        } else if (key == 0) {
            if (a2.flag)
                return 0;
        }
        int i = FUN_000f6660(cur - 1, 0x80);
        while (i != cur) {
            FELayout *w = widgets[i];
            if (w && w->v19()) {
                setWidget(widgets[i], 1);
                return 1;
            }
            i = FUN_000f6660(i - 1, 0x80);
        }
        setWidget(widgets[cur], 1);
        return 1;
    }
    case 2:
    case 4: {
        a2.flag = 0;
        if (widgets[cur]) {
            SingleLayout *sl = dynamic_cast<SingleLayout *>(widgets[cur]);
            if (sl)
                a2.flag = sl->v22();
        }
        if (key == 2) {
            if (!a2.flag)
                return 0;
        } else if (key == 4) {
            if (a2.flag)
                return 0;
        }
        int i = (cur + 1) % 0x80;
        while (i != cur) {
            FELayout *w = widgets[i];
            if (w && w->v19()) {
                setWidget(widgets[i], 2);
                return 1;
            }
            i = (i + 1) % 0x80;
        }
        setWidget(widgets[cur], 2);
        return 1;
    }
    default:
        return 0;
    }
}
