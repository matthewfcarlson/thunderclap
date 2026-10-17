// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00024280 @ 0x00024280
struct Entry { char pad[8]; int key1; int key2; };
struct Receiver { Entry* FUN_00059c10(int); };
struct Lookup { char pad[0x44]; Receiver* receiver; };
struct Table { Lookup* lookup; char pad[8]; int count; int items[1]; Entry* FUN_00024280(int key1, int key2); };
Entry* Table::FUN_00024280(int key1, int key2) {
    for (int i = 0; i < count; ++i) {
        Entry* result = lookup->receiver->FUN_00059c10(items[i]);
        if (result && result->key1 == key1 && result->key2 == key2)
            return result;
    }
    return 0;
}