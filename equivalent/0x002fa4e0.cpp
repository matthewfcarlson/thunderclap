// STATUS: equivalent (tools/equiv.py level 3: 185 inputs, branch coverage 14/16, incomplete)
// FUN_002fa4e0 @ 0x002fa4e0
#include "decls/data/engine/physics.h"

struct Cell_2fa4e0 {
    char data[0x50];
    void FUN_002f9a80(unsigned int a, unsigned int b);
};

struct Pair_2fa4e0 {
    int first;
    int second;
};

struct CellGrid {
    Cell_2fa4e0 *cells;
    void FUN_002fa180(unsigned int n);
};

void *__cdecl FUN_0008d6d0(unsigned int size);


void FUN_002fa4e0(unsigned int n, unsigned int a, unsigned int b)
{
    (*(CellGrid*)&DAT_0055545c).FUN_002fa180(n);
    for (unsigned int i = 0; i < n; i++)
        (*(CellGrid*)&DAT_0055545c).cells[i].FUN_002f9a80(a, b);

    if ((*(Pair_2fa4e0**)&DAT_00555468) != 0)
        return;
    if (n != 0) {
        unsigned int bytes = n * sizeof(Pair_2fa4e0);
        Pair_2fa4e0 *p = (Pair_2fa4e0 *)FUN_0008d6d0(bytes);
        (*(Pair_2fa4e0**)&DAT_00555468) = p;
        if (p != 0) {
            (*(Pair_2fa4e0**)&DAT_0055546c) = (Pair_2fa4e0 *)((char *)p + bytes);
            for (unsigned int i = n; i != 0; i--, p++) {
                if (p != 0) {
                    p->first = 0;
                    p->second = -1;
                }
            }
            return;
        }
    }
    (*(Pair_2fa4e0**)&DAT_00555468) = 0;
    (*(Pair_2fa4e0**)&DAT_0055546c) = 0;
}
