struct CollisionAnalyser_30d900 {
    int pad;
    int* begin;
    int* end;
    int Find(int* key);
};
extern int* gCache_30d900;
int CollisionAnalyser_30d900::Find(int* key) {
    int* first = begin;
    int* last = end;
    if (first > last)
        return 0;
    if (!(gCache_30d900 <= last && gCache_30d900 >= first)) {
        gCache_30d900 = first;
    }
    int* p = gCache_30d900;
    int* start = p;
    do {
        if (key[0] == p[0] && key[2] == p[2] && key[1] == p[1] && key[3] == p[3]) {
            gCache_30d900 = p;
            return p[4];
        }
        if (p == last)
            p = first;
        else
            p += 5;
    } while (p != start);
    gCache_30d900 = p;
    return 0;
}