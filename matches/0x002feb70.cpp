typedef unsigned int uint_2feb70;
void __cdecl FUN_002feb70(uint_2feb70* p, int n, int limit, uint_2feb70 value) {
    int parent = (n - 1) / 2;
    if (limit < n) {
        do {
            uint_2feb70 x = p[parent];
            if (x >= value)
                break;
            p[n] = x;
            n = parent;
            parent = (n - 1) / 2;
        } while (limit < n);
    }
    p[n] = value;
}
