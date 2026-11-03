#include "gen/owners.h"
struct Row_2e55e0 {
    int* p;
    int pad[2];
};
struct Obj_2e55e0 {
    char pad[0x14];
    Row_2e55e0* mRows;
    int target(int a, int b);
};
int Obj_2e55e0::target(int a, int b) {
    if (((owners::SortedArray_2e5330 *)this)->FUN_002e5330((unsigned int)a, (unsigned int *)(&a)) == true) {
        return mRows[a].p[b];
    }
    return 0;
}
