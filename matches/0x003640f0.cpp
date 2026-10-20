struct Item {
    char bytes[8];
    void FUN_0027af50();
};
extern Item DAT_004e58c0[];
void FUN_003640f0() {
    Item* p = DAT_004e58c0 + 4;
    for (int i = 0; i < 0x108; ++i) {
        p -= 4;
        (p - 3)->FUN_0027af50();
        (p - 4)->FUN_0027af50();
        (p - 5)->FUN_0027af50();
    }
}