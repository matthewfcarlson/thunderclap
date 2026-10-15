struct Entry {
    char pad0[0x30];
    void* a;
    void* aCopy;
    char pad1[8];
    void* b;
    void* bCopy;
    char pad2[8];
};
void __cdecl release(void*);
void __cdecl fn(Entry* first, Entry* last) {
    for (; first != last; ++first) {
        void* b = first->b;
        first->bCopy = b;
        if (b)
            release(b);
        void* a = first->a;
        first->aCopy = a;
        if (a)
            release(a);
    }
}