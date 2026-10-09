void Rot(unsigned* a, unsigned* b, unsigned* c, int d, int e);
void Fn(unsigned* first, unsigned* last) {
    if (first != last) {
        unsigned* i = first + 1;
        if (i != last) {
            unsigned* j = first + 2;
            do {
                unsigned v = *i;
                unsigned* p = first;
                if (v < *first) {
                    if (p != i && i != j)
                        Rot(p, i, j, 0, 0);
                } else {
                    unsigned* q = j - 2;
                    if (v < *q) {
                        do {
                            p = q;
                            q = p - 1;
                        } while (v < *q);
                        if (p != i && i != j)
                            Rot(p, i, j, 0, 0);
                    }
                }
                i = i + 1;
                j = j + 1;
            } while (i != last);
        }
    }
}
