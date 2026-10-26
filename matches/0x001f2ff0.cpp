#include "decls/data/game/global.h"
// data: count = DAT_004e3764, entries = DAT_004e37b8

struct Entry {
    unsigned __int64 key;
    char pad[24];
};
Entry* Find(unsigned __int64* k) {
    int n = DAT_004e3764;
    for (int i = 0; i < n; i++) {
        unsigned __int64 v = *k;
        if (((Entry*)&DAT_004e37b8)[i].key == v)
            return &((Entry*)&DAT_004e37b8)[i];
    }
    return 0;
}