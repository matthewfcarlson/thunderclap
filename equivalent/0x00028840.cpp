// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00028840 @ 0x00028840
typedef unsigned __int64 Key_28840;
extern Key_28840 __cdecl FUN_002672f0(const char*, int, int);

struct Focus_28840 {
    void FUN_001cc620(int mode);
};
struct Root_28840 {
    char pad[0x2c];
    Focus_28840* focus;
};

struct Entry_28840 {
    void FUN_0003b1c0(float value, int flag);
    void FUN_0003ea10(int flag);
};

struct Owner_28840 {
    Root_28840* root;
    char pad04[0x120];
    Entry_28840* current;
    Entry_28840* FUN_00024280(Key_28840 key);
    void FUN_00028840(const char* name, float value);
};

void Owner_28840::FUN_00028840(const char* name, float value)
{
    Entry_28840* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (entry) {
        entry->FUN_0003b1c0(value, 1);
        if (value <= 0.0f) {
            if (entry == current) {
                root->focus->FUN_001cc620(2);
            } else {
                entry->FUN_0003ea10(1);
            }
        }
    }
}
