struct Receiver_ea0c0 {
    virtual void vfunc_0();
};
struct Notify_ea0c0 {
    void FUN_000f8b90(int);
};
struct Item_ea0c0 {
    int owner;
    char pad[0x20];
    int field24;
    Receiver_ea0c0* receiver;
    int field2c;
    int field30;
    unsigned char enabled;
    char tail[3];
    void FUN_000f83c0(const char*);
};
struct TextSelector {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
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
    virtual void vfunc_19(const char*, unsigned char, Receiver_ea0c0*);
    char pad04[0xa0];
    int owner;
    char padA8[0xa8];
    int selected;
    int previous;
    Item_ea0c0 items[128];
    int count;
    char pad1d5c[0x38];
    Notify_ea0c0* notify;
};
void TextSelector::vfunc_19(const char* text, unsigned char select, Receiver_ea0c0* receiver) {
    if (count >= 128)
        return;
    items[count].FUN_000f83c0(text);
    items[count].owner = owner;
    items[count].field24 = 0;
    items[count].receiver = receiver;
    if (receiver)
        items[count].receiver->vfunc_0();
    items[count].field2c = 0;
    items[count].field30 = 0;
    items[count].enabled = 1;
    if (select) {
        int index = count;
        previous = index;
        selected = index;
        if (notify)
            notify->FUN_000f8b90(index);
        vfunc_0();
    }
    ++count;
}
