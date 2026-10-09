typedef unsigned int u32;
extern void __cdecl releaseThing(u32);
struct Entry {
    u32 value;
    char pad[12];
};
void __cdecl FUN_002b1390(Entry* begin, Entry* end) {
    for (; begin != end; ++begin) {
        if (begin->value != 0)
            releaseThing(begin->value);
    }
}