typedef unsigned int u32;
struct Item {
    char pad[0x10];
    u32 value;
};
extern u32* PTR_LOOP;
extern Item* FindItem(void* table, u32* key);
u32 FUN_00263df0(u32 a, u32 b) {
    u32 key[2];
    key[0] = a;
    key[1] = b;
    Item* p = FindItem(&PTR_LOOP, key);
    if (p)
        return p->value;
    return 0;
}