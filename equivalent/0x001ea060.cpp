// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001ea060 @ 0x001ea060
int __cdecl FUN_002673a0(int, int);
struct Entry {
    char pad0[0x14];
    Entry *next;
    char pad1[0x20];
    int key;
};
struct List {
    char pad[0x3c];
    Entry *first;
};
int __stdcall FUN_001ea060(List *list, int value) {
    if (!list) return -1;
    int key = FUN_002673a0(value, 0);
    Entry *entry = list->first ? (Entry *)((char *)list->first - 0x14) : 0;
    int index = 0;
    while (entry) {
        if (entry->key == key) return index;
        entry = entry->next ? (Entry *)((char *)entry->next - 0x14) : 0;
        ++index;
    }
    return -1;
}