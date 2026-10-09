struct Inner {
    char pad[0x18];
};
struct Item {
    char pad[0x44];
    Inner* p;
};
extern char gFallback;
struct Table {
    void** slots;
    void* Get(unsigned int key);
};
void* Table::Get(unsigned int key) {
    Item* item = (Item*)slots[(((int)key >> 16) & 0xffff)];
    if (item) {
        unsigned short lo = (unsigned short)key;
        return (char*)(*(void**)((char*)item->p + 0x18)) + lo * 24;
    }
    return &gFallback;
}
