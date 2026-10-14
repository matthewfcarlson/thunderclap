// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 34/34)
// FEMemCardControl::vfunc_5 @ 0x000d8680
struct Metrics_d8680 { int dummy; };

class Fonts_d8680 {
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
    virtual Metrics_d8680 *v44();
};

struct Hold_d8680 {
    char pad0[4];
    Fonts_d8680 *fonts;
};

class Owner_d8680 {
public:
    char pad0[8];
    Hold_d8680 *hold;
};

class Provider_d8680 {
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
    virtual void v15(int a);
    virtual void v16(int a);
};

struct ProviderRef_d8680 {
    Provider_d8680 *provider;
    void FUN_00293d00(void *state);
};

struct Player_d8680 {
    char pad0[0x9a8];
    char busy;
};

class Game_d8680 {
public:
    char pad0[0x2218];
    Player_d8680 *player;
};

Game_d8680 *FUN_000fc3d0();

struct Entry_d8680 {
    int a;
    int b;
    float scale;
};

struct Slot_d8680 {
    float weight;
    int a;
    int b;
    int value;
};

struct SlotStack_d8680 {
    Slot_d8680 slots[8];
    int index;
    float scale;
    void FUN_000f78f0();
};

struct Layout_d8680 {
    Metrics_d8680 *font;
    int current;
    SlotStack_d8680 stack;
    Layout_d8680 *FUN_000f7fe0(Metrics_d8680 *font);
    void FUN_000f87f0(Entry_d8680 *e, void *arg);
    void FUN_000f78e0();
};

struct Item_d8680 {
    Entry_d8680 entry;
    char pad[0x38 - sizeof(Entry_d8680)];
};

struct Rec_d8680 {
    Entry_d8680 entry;
    char pad0c[0x30 - sizeof(Entry_d8680)];
    char hasEntry;
    char pad31[7];
    char selected;
    char pad39[3];
};

extern ProviderRef_d8680 *DAT_0052c2ac;
extern unsigned int DAT_004a0cfc;
extern unsigned int DAT_004a0d00;
extern unsigned int DAT_004a0d08;
extern unsigned int DAT_004a0d0c;
extern unsigned int DAT_004a0d10;
extern unsigned int DAT_004a0d14;

class FEMemCardControl {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x14 - 4];
    Owner_d8680 *owner;
    char pad18[0x154 - 0x18];
    char state154[0x178 - 0x154];
    char cells[5][12];
    char pad1b4[0x1d0 - 0x1b4];
    int sel;
    int sel2;
    char pad1d8[0x220 - 0x1d8];
    Rec_d8680 recs[5];
    char pad34c[0x35c - (0x220 + 5 * 0x3c)];
    Item_d8680 items[1];
    char pad394[0x3a8 - (0x35c + 0x38)];
    char flag3a8;
    char pad3a9[0x3ac - 0x3a9];
    int mode;
    char pad3b0[4];
    char block3b4[0x3c4 - 0x3b4];
    unsigned int color3c4;
    char pad3c8[0x3d0 - 0x3c8];
    char block3d0[4];

    float FUN_000e2840();
    float FUN_000e2850();
};

void FEMemCardControl::vfunc_5()
{
    Layout_d8680 layout;
    SlotStack_d8680 *st = &layout.stack;

    layout.FUN_000f7fe0(owner->hold->fonts->v44());
    st->slots[st->index].value = DAT_004a0cfc;
    {
        float k = FUN_000e2850();
        st->slots[st->index].weight = FUN_000e2840() * k;
    }
    st->slots[st->index].b = 2;

    Player_d8680 *pl = FUN_000fc3d0()->player;
    if ((pl == 0 || !pl->busy) && mode != 0x20 && (mode == 3 || mode == 5 || mode == 4 || mode == 7)) {
        st->slots[st->index].a = 1;
        DAT_0052c2ac->provider->v15(0);
        DAT_0052c2ac->FUN_00293d00(state154);
        layout.FUN_000f87f0(&items[sel].entry, 0);
        DAT_0052c2ac->provider->v16(0);
        st->slots[st->index].a = 1;

        char *cell = cells[0];
        for (int i = 0; i < 5; i++) {
            if (i > 0 && !recs[i].hasEntry && !recs[i - 1].hasEntry)
                break;
            void *arg = 0;
            st->FUN_000f78f0();
            if (recs[i].selected) {
                st->slots[st->index].value = DAT_004a0d08;
                if (i == sel2) {
                    arg = block3b4;
                    color3c4 = DAT_004a0d14;
                }
            } else if (i == sel2) {
                st->slots[st->index].value = DAT_004a0cfc;
                arg = block3b4;
                color3c4 = DAT_004a0d10;
            } else {
                st->slots[st->index].value = DAT_004a0d00;
                arg = block3d0;
            }
            DAT_0052c2ac->provider->v15(0);
            DAT_0052c2ac->FUN_00293d00(cell);
            Entry_d8680 *e;
            if (!recs[i].hasEntry) {
                if (!flag3a8)
                    st->slots[st->index].value = DAT_004a0d0c;
                e = (Entry_d8680 *)((char *)items + 0x28);
            } else {
                e = &recs[i].entry;
            }
            layout.FUN_000f87f0(e, arg);
            DAT_0052c2ac->provider->v16(0);
            if (st->index > 0)
                st->index--;
            cell += 12;
        }
    }
    layout.FUN_000f78e0();
}
