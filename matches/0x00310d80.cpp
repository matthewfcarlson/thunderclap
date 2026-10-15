// Same code shape as 0x002feb70 (propagated; names are from that function)
typedef unsigned int uint_310d80;
void __cdecl FUN_00310d80(uint_310d80* p, int n, int limit, uint_310d80 value) {
    int parent = (n - 1) / 2;
    if (limit < n) {
        do {
            uint_310d80 x = p[parent];
            if (x >= value)
                break;
            p[n] = x;
            n = parent;
            parent = (n - 1) / 2;
        } while (limit < n);
    }
    p[n] = value;
}
