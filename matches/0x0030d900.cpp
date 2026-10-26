#include "decls/data/engine/physics.h"
// data: gCache_30d900 = DAT_00555494

struct CollisionAnalyser_30d900 {
    int pad;
    int* begin;
    int* end;
    int Find(int* key);
};
int CollisionAnalyser_30d900::Find(int* key) {
    int* first = begin;
    int* last = end;
    if (first > last)
        return 0;
    if (!((*(int**)&DAT_00555494) <= last && (*(int**)&DAT_00555494) >= first)) {
        (*(int**)&DAT_00555494) = first;
    }
    int* p = (*(int**)&DAT_00555494);
    int* start = p;
    do {
        if (key[0] == p[0] && key[2] == p[2] && key[1] == p[1] && key[3] == p[3]) {
            (*(int**)&DAT_00555494) = p;
            return p[4];
        }
        if (p == last)
            p = first;
        else
            p += 5;
    } while (p != start);
    (*(int**)&DAT_00555494) = p;
    return 0;
}