#include "compat/ptr.h"
#include "decls/address.h"
extern const char S1[], S2[], S3[];
extern int VTable_2dc60;
struct Base_2dc60 {
    Base_2dc60(const char*, int);
};
struct Target_2dc60 : Base_2dc60 {
    char pad0[16];
    unsigned char b10, b11, b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int field1c;
    Target_2dc60(const char*, int);
};
Target_2dc60::Target_2dc60(const char* a, int x) : Base_2dc60(a, 3) {
    *(hulk_intptr*)this = (hulk_intptr)&VTable_2dc60;
    field1c = x;
    b18 = FUN_001d04d0(S1);
    b10 = FUN_001d04d0(S2);
    b11 = FUN_001d04d0(S2);
    b12 = FUN_001d04d0(S3);
}