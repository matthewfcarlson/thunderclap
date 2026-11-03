#include "gen/owners.h"
struct E_25720 {
    char x[0x50];
    int key;
    char y[0x10];
    char flag;
};
void owners::C_25720::FUN_00025720(int key) {
    int n = count;
    int i = 0;
    if (n > 0) {
        E_25720* p = (E_25720*)((char*)this + 0x590);
        do {
            if (p->key == key) {
                p->flag = 1;
                return;
            }
            ++i;
            p = (E_25720*)((char*)p + 0x68);
        } while (i < n);
    }
}