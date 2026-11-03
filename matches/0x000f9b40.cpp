#include "gen/owners.h"
void owners::Node_f9b40::FUN_000f9b40(owners::Node_f9b40* p) {
    owners::Node_f9b40* cur = this;
    if (cur != p) {
        do {
            if (cur->next == 0) {
                cur->next = p;
                return;
            }
            cur = cur->next;
        } while (cur != p);
    }
}
