class Entry_1cb930 {
  public:
    int first;
    int second;
    char pad[0x20];
    bool Check(int);
};
class Owner_1cb930 {
  public:
    char pad[0x24];
    Entry_1cb930 entries[24];
    bool Find(int);
};
bool Owner_1cb930::Find(int value) {
    unsigned int i = 0;
    Entry_1cb930* entry = &entries[0];
    do {
        int a = entry->first;
        int b = entry->second;
        bool found = entry->Check(value);
        if (value == a || value == b || found)
            return true;
        ++i;
        entry = (Entry_1cb930*)((char*)entry + 0x28);
    } while (i < 24);
    return false;
}