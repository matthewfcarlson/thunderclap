extern "C" int strcmp(const char*, const char*);
struct Item_e6530 {
    char pad[0x18];
    char name[1];
};
struct FEThingsBase_e6530 {
    char pad[0x160c];
    Item_e6530* items[64];
    Item_e6530* Find(const char* s);
};
Item_e6530* FEThingsBase_e6530::Find(const char* s) {
    for (int i = 0; i < 64; i++) {
        if (items[i] && strcmp(items[i]->name, s) == 0)
            return items[i];
    }
    return 0;
}
