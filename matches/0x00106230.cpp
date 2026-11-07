struct Key {
    char pad[8];
    unsigned __int64 key;
};
struct Obj {
    char pad[8];
    int count;
    Key** items;
    Key* find(const char* name);
};
extern "C" unsigned __int64 __cdecl FUN_0027afb0(const char* name);
// the entry whose key is the name's hash key (0x0027afb0)
Key* Obj::find(const char* name) {
    unsigned __int64 k = FUN_0027afb0(name);
    for (int i = 0; i < count; ++i) {
        Key* p = items[i];
        if (p->key == k)
            return items[i];
    }
    return 0;
}