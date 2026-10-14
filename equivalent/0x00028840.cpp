// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00028840 @ 0x00028840
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char*, int, int);

struct Focus {
    void FUN_001cc620(int mode);
};
struct Root {
    char pad[0x2c];
    Focus* focus;
};

struct Entry {
    void FUN_0003b1c0(float value, int flag);
    void FUN_0003ea10(int flag);
};

struct Owner {
    Root* root;
    char pad04[0x120];
    Entry* current;
    Entry* FUN_00024280(Key key);
    void FUN_00028840(const char* name, float value);
};

void Owner::FUN_00028840(const char* name, float value)
{
    Entry* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
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
