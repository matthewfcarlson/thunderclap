// STATUS: equivalent (tools/equiv.py level 3: 1739 inputs, branch coverage 10/10)
// FUN_001e9860 @ 0x001e9860
struct Entry { char pad[0x10]; int first; int second; };
struct Owner { char pad[8]; Entry* entries[100]; int count; Entry* FUN_001e9860(int first, int second); };
Entry* Owner::FUN_001e9860(int first, int second) {
    for (int i = 0; i < count; ++i) {
        Entry* entry = entries[i];
        if (entry && entry->first == first && entry->second == second)
            return entries[i];
    }
    return 0;
}