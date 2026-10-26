#include "decls/data/engine/audio.h"
// data: g0_24cab0 = DAT_004e62b0

typedef unsigned int U_24cab0;
void f(U_24cab0* a, U_24cab0* b) {
    if (a) {
        (*(U_24cab0*)&DAT_004e62b0) = a[0];
        (*(U_24cab0*)&DAT_004e62b4) = a[1];
        (*(U_24cab0*)&DAT_004e62b8) = a[2];
    }
    if (b) {
        (*(U_24cab0*)&DAT_004e62bc) = b[0];
        (*(U_24cab0*)&DAT_004e62c0) = b[1];
        (*(U_24cab0*)&DAT_004e62c4) = b[2];
    }
}