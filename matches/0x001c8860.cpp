class C { public: char pad[0x138]; int items[256]; volatile unsigned int count; void Remove(int value); };
void C::Remove(int value) {
    unsigned int n = count;
    unsigned int i = 0;
    if (n > 0) {
        int *p = items;
        do {
            if (*p == value) {
                unsigned int m = n - 1;
                count = m;
                items[i] = items[m];
                return;
            }
            ++i; ++p;
        } while (i < count);
    }
}
