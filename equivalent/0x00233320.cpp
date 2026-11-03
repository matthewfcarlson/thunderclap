// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00233320 @ 0x00233320
#include "gen/owners.h"
owners::Node_233320 *owners::Node_233320::FUN_00233320(int first, int second) {
    if (key1 == first && key2 == second) return this;
    for (owners::Node_233320 *node = child; node != 0; node = node->next) {
        if (node->key1 == first && node->key2 == second) return node;
    }
    return 0;
}