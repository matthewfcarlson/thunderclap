extern "C" char DAT_004246cc[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern "C" char DAT_0049cad8[];
struct Base {
    unsigned int vt;
    void Init(void*, int);
};
extern char FUN_001d04d0(const void*);
struct Target : Base {
    char pad04[0x0c];
    char m10;
    char m11;
    char m12;
    char pad13[5];
    char m18;
    char pad19[3];
    void* m1c;
    Target* Run(void*, void*);
};
Target* Target::Run(void* a, void* b) {
    Init(a, 3);
    vt = ((int)DAT_004246cc);
    m1c = b;
    m18 = FUN_001d04d0((void*)((int)DAT_0048e100));
    m10 = FUN_001d04d0((void*)((int)DAT_0049cad8));
    m11 = FUN_001d04d0((void*)((int)DAT_0049cad8));
    m12 = FUN_001d04d0((void*)((int)DAT_0048e128));
    return this;
}