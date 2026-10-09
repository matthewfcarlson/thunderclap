class Entry { public: int first; int second; char pad[0x20]; bool Check(int); };
class Owner { public: char pad[0x24]; Entry entries[24]; bool Find(int); };
bool Owner::Find(int value) {
    unsigned int i = 0;
    Entry *entry = &entries[0];
    do {
        int a = entry->first;
        int b = entry->second;
        bool found = entry->Check(value);
        if (value == a || value == b || found) return true;
        ++i;
        entry = (Entry *)((char *)entry + 0x28);
    } while (i < 24);
    return false;
}