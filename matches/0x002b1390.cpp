typedef unsigned int u32_2b1390;
extern void __cdecl releaseThing(u32_2b1390);
struct Entry_2b1390 {
    u32_2b1390 value;
    char pad[12];
};
void __cdecl FUN_002b1390(Entry_2b1390* begin, Entry_2b1390* end) {
    for (; begin != end; ++begin) {
        if (begin->value != 0)
            releaseThing(begin->value);
    }
}