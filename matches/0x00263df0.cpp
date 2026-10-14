typedef unsigned int u32_263df0;
struct Item_263df0 {
    char pad[0x10];
    u32_263df0 value;
};
extern u32_263df0* PTR_LOOP;
extern Item_263df0* FindItem(void* table, u32_263df0* key);
u32_263df0 FUN_00263df0(u32_263df0 a, u32_263df0 b) {
    u32_263df0 key[2];
    key[0] = a;
    key[1] = b;
    Item_263df0* p = FindItem(&PTR_LOOP, key);
    if (p)
        return p->value;
    return 0;
}