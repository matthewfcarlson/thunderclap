extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042bf6c[];
extern "C" char DAT_004342e8[];
extern "C" char DAT_004342fc[];
extern "C" void* Allocate(void*, unsigned int);
extern "C" void Init();
extern "C" volatile unsigned int gStored;
extern "C" volatile void* gResult_3351a0;
struct Callback_3351a0 {
    unsigned int vtable;
    unsigned int arg;
    unsigned int subVtable;
    unsigned int field;
};
void CreateCallback(unsigned int arg) {
    gStored = arg;
    Callback_3351a0* p = (Callback_3351a0*)Allocate((void*)arg, 0x10);
    if (p) {
        p->vtable = ((int)DAT_0042afa8);
        p->arg = gStored;
        Init();
        *(volatile unsigned int*)&p->subVtable = ((int)DAT_0042bf6c);
        p->vtable = ((int)DAT_004342fc);
        p->subVtable = ((int)DAT_004342e8);
        p->field = 0;
        gResult_3351a0 = p;
    } else
        gResult_3351a0 = 0;
}