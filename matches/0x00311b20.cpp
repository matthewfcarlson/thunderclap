void Rot(unsigned* a, unsigned* b, unsigned* c, int d, int e);

void FUN_00311b20(unsigned* first, unsigned* last) {
    if (first == last)
        return;
    unsigned* i = first + 1;
    while (i != last) {
        unsigned v = *i;
        if (v < *first) {
            if (first != i && i != i + 1)
                Rot(first, i, i + 1, 0, 0);
        } else if (v < *(i - 1)) {
            unsigned* p = i - 1;
            unsigned* q;
            do {
                q = p;
                p--;
            } while (v < *p);
            if (q != i && i != i + 1)
                Rot(q, i, i + 1, 0, 0);
        }
        i++;
    }
}
