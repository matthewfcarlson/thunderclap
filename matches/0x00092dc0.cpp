typedef unsigned char u8;
typedef int i32;
struct Entry { char pad[8]; u8 value; };
struct Table {
    Entry* items[0x2fe];
    u8 Get(i32 index);
};
u8 Table::Get(i32 index) {
    if (index < 0 || index >= 0x2fe) return 0;
    return items[index]->value;
}