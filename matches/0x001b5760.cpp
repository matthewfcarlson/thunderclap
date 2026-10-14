struct Inner_1b5760 {
    char pad[0x18];
};
struct Item_1b5760 {
    char pad[0x44];
    Inner_1b5760* p;
};
extern char gFallback_1b5760;
struct Table_1b5760 {
    void** slots;
    void* Get(unsigned int key);
};
void* Table_1b5760::Get(unsigned int key) {
    Item_1b5760* item = (Item_1b5760*)slots[(((int)key >> 16) & 0xffff)];
    if (item) {
        unsigned short lo = (unsigned short)key;
        return (char*)(*(void**)((char*)item->p + 0x18)) + lo * 24;
    }
    return &gFallback_1b5760;
}
