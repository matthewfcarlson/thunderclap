// STATUS: equivalent (tools/equiv.py level 3: 1583 inputs, branch coverage 12/12)
// FUN_0023ae90 @ 0x0023ae90
struct Entry { unsigned key1; unsigned key2; unsigned flags; char padding[12]; };
struct ScriptReader_23ae90 { char padding[0x12c]; int count; Entry entries[1]; int FUN_0023ae90(unsigned key1, unsigned key2, unsigned mask); };
int ScriptReader_23ae90::FUN_0023ae90(unsigned key1, unsigned key2, unsigned mask) {
    int first = -1;
    for (int i = 0; i < count; ++i) {
        Entry &entry = entries[i];
        if (entry.key1 == key1 && entry.key2 == key2) {
            if (entry.flags & mask) return i;
            if (first < 0) first = i;
        }
    }
    return first;
}