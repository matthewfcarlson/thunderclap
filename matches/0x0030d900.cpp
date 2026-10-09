struct Range {
    int pad;
    int* begin;
    int* end;
    int Find(int* key);
};
extern int* gCache;
int Range::Find(int* key) {
    int* first = begin;
    int* last = end;
    if (first > last)
        return 0;
    if (!(gCache <= last && gCache >= first)) {
        gCache = first;
    }
    int* p = gCache;
    int* start = p;
    do {
        if (key[0] == p[0] && key[2] == p[2] && key[1] == p[1] && key[3] == p[3]) {
            gCache = p;
            return p[4];
        }
        if (p == last)
            p = first;
        else
            p += 5;
    } while (p != start);
    gCache = p;
    return 0;
}