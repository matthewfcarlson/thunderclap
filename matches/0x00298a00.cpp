#include "gen/owners.h"
void owners::X_298a00::FUN_00298a00(unsigned char value) {
    --count;
    map[items[value]] = 0xff;
    if (count != value) {
        unsigned char* it = items;
        it[value] = it[count];
        map[items[value]] = value;
    }
    items[count] = 0xff;
}
