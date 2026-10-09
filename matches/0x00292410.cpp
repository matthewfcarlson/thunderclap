extern "C" void* alloc(unsigned int);
extern "C" void init();
extern int* gA;
extern int* gB;
int* target() {
    if (gA == 0) {
        int* p = (int*)alloc(4);
        if (p != 0) *p = 0;
        else p = 0;
        gA = p;
        gB = p;
        init();
    }
    return gA;
}