// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_000c9100 @ 0x000c9100
struct Handle {
    unsigned int data[2];
    Handle* FUN_0027af00();
    void FUN_0027af70(Handle* other);
    void FUN_0027af50();
};
struct Entry {
    int id;
    int values[8];
    int reserved24;
    Handle handle;
    int state;
    int reserved34;
    int count;
    unsigned char active;
    char padding[3];
};
struct Manager {
    char padding0[0x20];
    unsigned char active;
    char padding21[0x237];
    Entry entries[128];
    void FUN_000c84e0(int index);
    void FUN_000c9100(int index);
};
void Manager::FUN_000c9100(int index) {
    if (index < 0 || index >= 128) return;
    Entry* entry = &entries[index];
    if (entry->id == -1 || !entry) return;
    if (entry->active == 1) active = 0;
    entry->id = -1;
    Handle temporary;
    Handle* result = temporary.FUN_0027af00();
    entry->handle.FUN_0027af70(result);
    temporary.FUN_0027af50();
    entry->state = -1;
    for (int i = 0; i < 8; ++i) entry->values[i] = 0;
    entry->count = 0;
    entry->active = 0;
    FUN_000c84e0(index);
}