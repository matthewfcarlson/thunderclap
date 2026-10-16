// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 10/10)
// FUN_001cb990 @ 0x001cb990
struct QueryArg { void FUN_0027af50(); int value; };
struct Entry { int unknown; int type; char padding[0x10]; int first; int second; char rest[0xc0]; };
struct Container {
    char padding[0xc];
    Entry *begin;
    Entry *end;
    bool FUN_001cb990(QueryArg key, int second);
};
bool Container::FUN_001cb990(QueryArg key, int second) {
    Entry *entry = end;
    while (entry != begin) {
        --entry;
        if (entry->type == 0x1b && entry->first == key.value && entry->second == second) {
            key.FUN_0027af50();
            return true;
        }
    }
    key.FUN_0027af50();
    return false;
}