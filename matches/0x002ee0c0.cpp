typedef unsigned int uint;
struct Item {
    uint a, b, c, d, e;
};
struct Buffer {
    char pad0[4];
    Item* cur;
    Item* end;
    bool Add(Item* value);
};
bool Buffer::Add(Item* value) {
    Item* p = cur;
    if ((uint)p < (uint)end) {
        cur = p + 1;
        if (p)
            *p = *value;
        return true;
    }
    return false;
}