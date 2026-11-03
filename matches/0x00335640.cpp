#include "gen/owners.h"
struct Entry {
    char pad[8];
    int type;
};
struct Manager {
    char pad[0x44];
    int count;
};
struct Object {
    char pad[4];
    Manager* manager;
    int* values;
    int FUN_00335640(int index);
};
int Object::FUN_00335640(int index) {
    if (index < 0)
        return 0;
    if (index >= manager->count)
        return 0;
    if (((Entry *)((owners::Thing_337090 *)manager)->FUN_00337090(index))->type != 4)
        return 0;
    return values[index];
}