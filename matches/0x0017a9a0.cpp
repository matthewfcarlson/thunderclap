struct Param {
    char pad[0x18];
    Param* Init(const char* name);
};

void* operator new(unsigned int n);
void Register(void* reg, Param** arr, int n);
extern int gCount;
extern char gReg[];

struct Base {
    int vt;
    char pad[0xc];
    int f10;
    int f14;
    Base(const char* name);
};

void FUN_0017a9a0() {
    if (gCount == 0) {
        Param* arr[2];
        Param* a = (Param*)operator new(0x18);
        if (a) {
            a->Init("timeBegin");
            *(int*)a = 0x41872c;
            *(int*)((char*)a + 0x10) = 0x16f880;
            arr[0] = a;
        } else {
            arr[0] = 0;
        }
        Param* b = (Param*)operator new(0x18);
        if (b) {
            b->Init("power");
            *(int*)b = 0x41872c;
            *(int*)((char*)b + 0x10) = 0x16f8a0;
            arr[1] = b;
        } else {
            arr[1] = 0;
        }
        Register(gReg, arr, 2);
    }
    gCount++;
}
