#include "compat/ptr.h"
struct Item {
    char pad[0x10];
    char value;
};
struct Holder {
    char pad[0x14];
    Item** begin;
    Item** end;
    char pad2[8];
    unsigned short index;
    void FUN_002c3770(char value);
};
void Holder::FUN_002c3770(char value) {
    Item** it = begin;
    unsigned int i = 0;
    for (; i < (unsigned int)(((hulk_intptr)end - (hulk_intptr)begin) >> 2); ++i, ++it) {
        if ((*it)->value == value) {
            index = (unsigned short)i;
            return;
        }
    }
}