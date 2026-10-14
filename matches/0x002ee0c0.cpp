typedef unsigned int uint;
struct Item_2ee0c0 {
    uint a, b, c, d, e;
};
struct Buffer_2ee0c0 {
    char pad0[4];
    Item_2ee0c0* cur;
    Item_2ee0c0* end;
    bool Add(Item_2ee0c0* value);
};
bool Buffer_2ee0c0::Add(Item_2ee0c0* value) {
    Item_2ee0c0* p = cur;
    if ((uint)p < (uint)end) {
        cur = p + 1;
        if (p)
            *p = *value;
        return true;
    }
    return false;
}