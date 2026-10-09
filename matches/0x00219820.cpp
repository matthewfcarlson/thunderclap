int Find(int* a, int b, int c) {
    int n = *(int*)((char*)a + 0x38), i = 0;
    if (n > 0) {
        int* p = (int*)(*(int*)((char*)a + 0x18) + 8);
        do {
            if (p[-1] > c) return 0;
            if (c < *p && --b == 0) {
                int* q = (int*)*(int*)((char*)a + 0x18);
                return q[i * 3] + 16;
            }
            ++i; p += 3;
        } while (i < n);
    }
    return 0;
}