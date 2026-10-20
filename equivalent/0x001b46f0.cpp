// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 11/11)
// FUN_001b46f0 @ 0x001b46f0
#include "decls/data/game/global.h"

struct Data {
    char reserved[8];
    unsigned int first;
    unsigned int second;
    unsigned int* value;
    char* FUN_00036d00();
};
struct Node {
    char reserved[8];
    Data* data;
    unsigned int type;
};
extern void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
char* __cdecl FUN_001b46f0(Node* node, unsigned int* output)
{
    if (!node) return 0;
    switch (node->type) {
    case 1: {
        Data* data = node->data;
        char* result = data->FUN_00036d00();
        *output = *data->value;
        return result;
    }
    case 5:
        FUN_00096d50(((char*)&DAT_004e21a0), 64, node->data->first, node->data->second);
        return ((char*)&DAT_004e21a0);
    case 6: return "projectile";
    case 7: return "civilian";
    default: return 0;
    }
}