// STATUS: equivalent (tools/equiv.py level 3: 2810 inputs, branch coverage 20/20)
// FUN_001eadf0 @ 0x001eadf0
struct Entry {
    int state;
    char pad[12];
    int blocked;
    void FUN_001ea700();
};
struct Manager {
    bool FUN_00266750();
    void FUN_00263e90();
};
extern Manager* DAT_004e3694;
void __cdecl FUN_002656a0();
void __cdecl thunk_FUN_00270a50();
struct Object {
    char pad[0x29];
    unsigned char active;
    char pad2[2];
    Entry* entries[64];
    int count;
    bool FUN_001eadf0();
};
bool Object::FUN_001eadf0() {
    for (int i = 0; i < count; ++i) {
        if (entries[i] && entries[i]->blocked == 0 && entries[i]->state != 0) {
            entries[i]->FUN_001ea700();
            while (entries[i]->state != 0) {
                FUN_002656a0();
                thunk_FUN_00270a50();
                if (entries[i]->state == 3)
                    entries[i]->FUN_001ea700();
                Entry* entry = entries[i];
                if (entry->state == 1 && DAT_004e3694->FUN_00266750()) {
                    entry->state = 3;
                    DAT_004e3694->FUN_00263e90();
                    DAT_004e3694 = 0;
                }
            }
        }
    }
    active = 0;
    return true;
}
