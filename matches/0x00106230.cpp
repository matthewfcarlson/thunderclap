struct Key {
    char pad[8];
    unsigned __int64 key;
};
struct Obj {
    char pad[8];
    int count;
    Key** items;
    Key* find(int x);
};
extern "C" unsigned __int64 __cdecl FUN_0027afb0(int);
Key* Obj::find(int x) {
    unsigned __int64 k = FUN_0027afb0(x);
    for (int i = 0; i < count; ++i) {
        Key* p = items[i];
        if (p->key == k)
            return items[i];
    }
    return 0;
}