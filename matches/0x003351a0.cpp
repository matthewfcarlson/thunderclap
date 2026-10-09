extern "C" void* Allocate(void*, unsigned int);
extern "C" void Init();
extern "C" volatile unsigned int gStored;
extern "C" volatile void* gResult;
struct Callback { unsigned int vtable; unsigned int arg; unsigned int subVtable; unsigned int field; };
void CreateCallback(unsigned int arg) {
    gStored = arg;
    Callback* p = (Callback*)Allocate((void*)arg, 0x10);
    if (p) {
        p->vtable = 0x42afa8;
        p->arg = gStored;
        Init();
        *(volatile unsigned int*)&p->subVtable = 0x42bf6c;
        p->vtable = 0x4342fc;
        p->subVtable = 0x4342e8;
        p->field = 0;
        gResult = p;
    } else gResult = 0;
}