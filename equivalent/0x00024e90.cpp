// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00024e90 @ 0x00024e90
#include "gen/owners.h"
struct Result {
    void* FUN_00035140(void* value);
};
struct Provider {
};
struct Header {
    char padding[0x44];
    Provider* provider;
};
struct Container {
    Header* header;
    char padding[8];
    int count;
    void* entries[1];
    void* FUN_00024e90(int index, void* value);
};
void* Container::FUN_00024e90(int index, void* value) {
    if (index < 0 || index >= count)
        return this;
    Result* result = ((Result *)((owners::ThisWrap_00059c10 *)(header->provider))->FUN_00059c10(entries[index]));
    return result->FUN_00035140(value);
}