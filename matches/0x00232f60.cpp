#include "gen/owners.h"
extern void* FUN_00344e74(owners::Node_232f60*, int, const void*, const void*, int);
extern const int DAT_0048e090;
extern const int DAT_004ca2b0;
void* owners::Node_232f60::FUN_00232f60() {
    if (type == 3)
        return FUN_00344e74(this, 0, &DAT_0048e090, &DAT_004ca2b0, 0);
    owners::Node_232f60* q = next;
    while (q != 0 && q->type != 3)
        q = q->next;
    return FUN_00344e74(q, 0, &DAT_0048e090, &DAT_004ca2b0, 0);
}