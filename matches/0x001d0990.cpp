extern "C" void* memcpy(void*, const void*, unsigned);
extern int g_heap;
void* Alloc(int, unsigned);
void Free(void*);
void* Realloc(int unused, void* p, unsigned oldSize, unsigned newSize) {
    if (newSize == 0) {
        if (p)
            Free(p);
        return 0;
    }
    void* n = Alloc(g_heap, newSize);
    if (!n)
        return 0;
    if (p) {
        if (oldSize > newSize)
            oldSize = newSize;
        memcpy(n, p, oldSize);
        Free(p);
    }
    return n;
}
