extern "C" unsigned char FUN_001d04d0(const char*);
extern const char S1[], S2[], S3[];
extern int VTable;
struct Base {
    Base(const char*, int);
};
struct Target : Base {
    char pad0[16];
    unsigned char b10, b11, b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int field1c;
    Target(const char*, int);
};
Target::Target(const char* a, int x) : Base(a, 3) {
    *(int*)this = (int)&VTable;
    field1c = x;
    b18 = FUN_001d04d0(S1);
    b10 = FUN_001d04d0(S2);
    b11 = FUN_001d04d0(S2);
    b12 = FUN_001d04d0(S3);
}