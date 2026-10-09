struct E {
    char d[0x44];
};
void F(E* a, E* b, E* c);

void G(E* first, E* mid, E* last) {
    int n = last - first;
    if (n > 40) {
        int s = (n + 1) / 8;
        F(first, first + s, first + s * 2);
        F(mid - s, mid, mid + s);
        F(last - s * 2, last - s, last);
        F(first + s, mid, last - s);
    } else {
        F(first, mid, last);
    }
}
