typedef unsigned char u8_92dc0;
typedef int i32_92dc0;
struct Entry_92dc0 {
    char pad[8];
    u8_92dc0 value;
};
struct Table_92dc0 {
    Entry_92dc0* items[0x2fe];
    u8_92dc0 Get(i32_92dc0 index);
};
u8_92dc0 Table_92dc0::Get(i32_92dc0 index) {
    if (index < 0 || index >= 0x2fe)
        return 0;
    return items[index]->value;
}