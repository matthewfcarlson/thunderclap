short* f(short* a, short* b) {
    if (a != b) {
        short* p = a + 1;
        if (p != b) {
            do {
                if (*a == *p)
                    goto found;
                a = p;
                ++p;
            } while (p != b);
            return b;
        found:
            p = p + 1;
            while (p != b) {
                if (*a != *p) {
                    a = a + 1;
                    *a = *p;
                }
                p = p + 1;
            }
            b = a + 1;
        }
    }
    return b;
}
