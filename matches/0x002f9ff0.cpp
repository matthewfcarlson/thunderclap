struct Item {
    void f(int);
};
extern "C" int __cdecl FUN_002f9ff0(Item* p, int count, int b) {
    if (count != 0) {
        int n = count;
        Item* q = p;
        do {
            if (q)
                q->f(b);
            q = (Item*)((char*)q + 0x50);
            --n;
        } while (n != 0);
        return (int)q;
    }
    return (int)p;
}
