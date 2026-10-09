extern "C" int strcmp(const char*, const char*);
struct Item {
    char pad[0x18];
    char name[1];
};
struct T {
    char pad[0x160c];
    Item* items[64];
    Item* Find(const char* s);
};
Item* T::Find(const char* s) {
    for (int i = 0; i < 64; i++) {
        if (items[i] && strcmp(items[i]->name, s) == 0)
            return items[i];
    }
    return 0;
}
