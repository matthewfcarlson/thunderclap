// STATUS: equivalent (tools/equiv.py level 3: 20041 inputs, branch coverage 135/136, incomplete)
// FUN_000c21b0 @ 0x000c21b0
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

class Entry;
class Manager {
  public:
    int FUN_000f7240(unsigned long long key);
    const unsigned short* FUN_000f7220(int id);
    int FUN_000f7d30(const char* name);
};
class Entry {
  public:
    char data[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const char* name, Manager* manager, char flag);
    void FUN_000f79a0(const unsigned short* text, int flag);
    void FUN_000f7a10(int id, int flag);
};

class CUnlockable {
  public:
    virtual void v0();
};
class CUnlockableMove : public CUnlockable {
  public:
    int FUN_00091f70();
    char FUN_00091f40();
    int FUN_00091f90();
    const unsigned long long* FUN_00092050();
    const char* FUN_00092040();
};
class UnlockTable {
  public:
    CUnlockable* FUN_00092ad0(int index);
    const unsigned long long* FUN_00092bb0(int index);
    const char* FUN_00092bc0(int index);
    char FUN_00092860(int index);
    char FUN_00092940(int index);
    char FUN_00092a40(int index);
    int FUN_000932a0(int index);
};

class FEControl {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    char pad0[0x141 - 4];
    char enabled;
    char pad1[0x154 - 0x142];
    int selected;
};
class FEObject {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
};
class IValueChangedReceiver {
  public:
    virtual void h0();
};
class IValueChangedSender {
  public:
    virtual void i0();
};
class TextSelector : public FEControl,
                     public FEObject,
                     public IValueChangedReceiver,
                     public IValueChangedSender {
  public:
    char pad2[0x1d58 - 0x158 - 12];
    int count;
    void FUN_000e36c0();
    virtual void v19(Entry* text, int a, int b);
    virtual void v20(int row, Entry* text);
    virtual void v21(int row, unsigned int enabled);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(int selected);
};
class TextButton : public FEControl,
                   public FEObject,
                   public IValueChangedReceiver,
                   public IValueChangedSender {
  public:
};
class TextLabel : public FEObject,
                  public IValueChangedReceiver,
                  public IValueChangedSender {
  public:
    char pad[0x18 - 12];
    Entry text;
};

class Sub {
  public:
    int FUN_00090110();
};
class Core {
  public:
    Sub* FUN_00086370();
};
class App {
  public:
    char pad[0x54];
    Core* core;
};
class Page {
  public:
    char FUN_000893c0();
};

extern App* DAT_004dd700;
Manager* __cdecl FUN_000fc1b0();
FEObject* __cdecl FUN_000fc260(const char* name);
void __cdecl FUN_000fb690(unsigned short* dst, const unsigned short* src, int count);
void __cdecl FUN_000fb790(unsigned short* dst, const char* src, int count);
void __cdecl FUN_000fc020(unsigned short* dst, int count, const unsigned short* fmt, int arg);
void __cdecl FUN_000964a0(char* dst, int size, const char* fmt, int value);

class UnlockMenu {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x34 - 0x14];
    Page* page;
    char pad2[0x4c - 0x38];
    UnlockTable* table;
    void FUN_000b7860(int arg);
    void FUN_000c1b50(int id, int lo, int hi);
    void FUN_000c21b0(volatile int id);
};

void UnlockMenu::FUN_000c21b0(volatile int id) {
    struct Frame {
        volatile int k;  // sel in the first block, loop index in the second
        volatile int row;
        volatile int sel;
        union { unsigned char b; unsigned int w; } unlocked;
        Entry text;
        int nameId;
        char numBuf[0x10];
        unsigned short wide[0x80];
        volatile unsigned int cookie;
    } frame;
    frame.cookie = DAT_004d9968;
    if (table == 0) {
        __security_check_cookie(frame.cookie);
        return;
    }
    frame.text.FUN_000f7930();
    frame.text.FUN_000f8500("", FUN_000fc1b0(), 1);
    bool refresh = true;
    do {
        if (id >= 0x34 && id <= 0x51) {
            const char* name = table->FUN_00092bc0(0x34);
            if (name == 0) {
                refresh = false;
                break;
            }
            TextSelector* list = dynamic_cast<TextSelector*>(FUN_000fc260(name));
            if (list == 0) {
                refresh = false;
                break;
            }
            frame.k = list->selected;
            list->FUN_000e36c0();
            for (int i = 0x34; i <= 0x51; i++) {
                const unsigned long long* key = table->FUN_00092bb0(i);
                if (*key == 0)
                    break;
                if (table->FUN_00092860(i))
                    continue;
                key = table->FUN_00092bb0(i);
                if (*key == 0)
                    continue;
                int stringId = FUN_000fc1b0()->FUN_000f7240(*key);
                if (stringId == -1)
                    continue;
                frame.text.FUN_000f8500("", FUN_000fc1b0(), 1);
                FUN_000fb690(frame.wide, FUN_000fc1b0()->FUN_000f7220(stringId), 0x80);
                if (table->FUN_00092a40(i))
                    FUN_000fb790(frame.wide, " \bnu", 0x80);
                frame.text.FUN_000f79a0(frame.wide, 0);
                list->v19(&frame.text, 0, 0);
            }
            int last = list->count - 1;
            if (frame.k >= 0) {
                if (frame.k > last)
                    frame.k = last;
            } else if (frame.k <= last) {
                frame.k = 0;
            } else {
                frame.k = last;
            }
            list->v25(frame.k);
            list->f3();
            TextButton* button = dynamic_cast<TextButton*>(FUN_000fc260("menu_item_blonsky_file"));
            if (button)
                button->enabled = (list->count != 0);
            FUN_000b7860(0);
        } else if ((id >= 0x266 && id <= 0x2c9) || id == 0x1d) {
            bool giftedAvailable = false;
            if (!table->FUN_00092860(0x1d))
                giftedAvailable = table->FUN_00092940(0x1d) != 0;
            CUnlockableMove* head = dynamic_cast<CUnlockableMove*>(table->FUN_00092ad0(0x266));
            if (head == 0) {
                refresh = false;
                break;
            }
            const char* listName = head->FUN_00092040();
            if (listName == 0) {
                refresh = false;
                break;
            }
            TextSelector* list = dynamic_cast<TextSelector*>(FUN_000fc260(listName));
            if (list == 0)
                break;
            frame.sel = list->selected;
            list->FUN_000e36c0();
            frame.row = 0;
            if (page->FUN_000893c0()) {
                frame.text.FUN_000f8500("TBS_CHEAT_SAVAGE_BANNER", 0, 1);
                list->v19(&frame.text, 0, 0);
                if (table->FUN_00092860(4)) {
                    FUN_000964a0(frame.numBuf, 0x10, "%d", 1000000);
                    frame.text.FUN_000f8500(frame.numBuf, FUN_000fc1b0(), 0);
                } else {
                    frame.text.FUN_000f8500("TBS_UNLOCKABLE_MOVE_ENABLED", FUN_000fc1b0(), 1);
                }
                list->v20(0, &frame.text);
                frame.row = 1;
            }
            for (frame.k = 0x266; frame.k <= 0x2c9; frame.k++) {
                int idx = table->FUN_000932a0(frame.k - 0x266);
                if (idx == -1)
                    continue;
                const unsigned long long* key = table->FUN_00092bb0(idx);
                if (*key == 0)
                    continue;
                if (table->FUN_00092860(idx) && !giftedAvailable)
                    continue;
                key = table->FUN_00092bb0(idx);
                if (*key == 0)
                    continue;
                int stringId = FUN_000fc1b0()->FUN_000f7240(*key);
                if (stringId == -1)
                    continue;
                frame.text.FUN_000f8500("", FUN_000fc1b0(), 1);
                FUN_000fb690(frame.wide, FUN_000fc1b0()->FUN_000f7220(stringId), 0x80);
                if (table->FUN_00092a40(idx))
                    FUN_000fb790(frame.wide, " \bnu", 0x80);
                frame.text.FUN_000f79a0(frame.wide, 0);
                list->v19(&frame.text, 0, 0);
                CUnlockableMove* move = dynamic_cast<CUnlockableMove*>(table->FUN_00092ad0(idx));
                if (move == 0) {
                    frame.row++;    // the original still counts the row (jumps to the increment)
                    continue;
                }
                int cost = move->FUN_00091f70();
                const unsigned long long* nameKey = move->FUN_00092050();
                frame.nameId = FUN_000fc1b0()->FUN_000f7240(*nameKey);
                if (cost <= 0) {
                    frame.text.FUN_000f8500("TBS_UNLOCKABLE_MOVE_GIFTED", FUN_000fc1b0(), 1);
                } else if (move->FUN_00091f40()) {
                    if (state == 9) {
                        frame.text.FUN_000f7a10(frame.nameId, 0);
                    } else {
                        frame.text.FUN_000f8500("TBS_UNLOCKABLE_MOVE_ENABLED", FUN_000fc1b0(), 1);
                    }
                } else {
                    FUN_000964a0(frame.numBuf, 0x10, "%d", cost);
                    frame.text.FUN_000f8500(frame.numBuf, FUN_000fc1b0(), 0);
                }
                list->v20(frame.row, &frame.text);
                frame.unlocked.b = 1;
                int requires = move->FUN_00091f90();
                if (requires != -1) {
                    CUnlockableMove* other = dynamic_cast<CUnlockableMove*>(table->FUN_00092ad0(requires));
                    if (other)
                        frame.unlocked.b = other->FUN_00091f40();
                }
                list->v21(frame.row, frame.unlocked.w);
                frame.row++;
            }
            int last = list->count - 1;
            if (frame.sel >= 0) {
                if (frame.sel > last)
                    frame.sel = last;
            } else if (frame.sel <= last) {
                frame.sel = 0;
            } else {
                frame.sel = last;
            }
            list->v25(frame.sel);
            list->f3();
            TextButton* button = dynamic_cast<TextButton*>(FUN_000fc260("menu_item_buy_menu"));
            if (button)
                button->enabled = (list->count != 0);
            TextLabel* label = dynamic_cast<TextLabel*>(FUN_000fc260("moves_list_smash_points"));
            if (label == 0)
                break;
            int points = DAT_004dd700->core->FUN_00086370()->FUN_00090110();
            Manager* strings = FUN_000fc1b0();
            FUN_000fc020(frame.wide, 0x40, strings->FUN_000f7220(strings->FUN_000f7d30("TBS_SMASH_POINTS_TOTAL")), points);
            label->text.FUN_000f79a0(frame.wide, 0);
        } else if (id >= 0x52 && id <= 0x8d) {
            FUN_000c1b50(id, 0x52, 0x8d);
        } else if (id >= 0x1bf && id <= 0x1f0) {
            FUN_000c1b50(id, 0x1bf, 0x1f0);
        } else if (id >= 0x1f1 && id <= 0x209) {
            FUN_000c1b50(id, 0x1f1, 0x209);
        } else if (id >= 0x258 && id <= 0x260) {
            FUN_000c1b50(id, 0x258, 0x260);
        } else if (id >= 0x20a && id <= 0x22d) {
            FUN_000c1b50(id, 0x20a, 0x22d);
        } else if (id >= 0x22e && id <= 0x243) {
            FUN_000c1b50(id, 0x22e, 0x243);
        } else if (id >= 0x244 && id <= 0x247) {
            FUN_000c1b50(id, 0x244, 0x247);
        } else if (id >= 0x248 && id <= 0x257) {
            FUN_000c1b50(id, 0x248, 0x257);
        }
    } while (0);
    if (refresh && id >= 0 && id <= 0x1f && !table->FUN_00092860(id)) {
        const char* name = table->FUN_00092bc0(id);
        if (name != 0) {
            TextSelector* row = dynamic_cast<TextSelector*>(FUN_000fc260(name));
            if (row != 0) {
                char hidden = table->FUN_00092940(id);
                row->enabled = 1;
                row->v25(hidden == 0);
            }
        }
    }
    frame.text.FUN_000f7960();
    __security_check_cookie(frame.cookie);
}
