// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026dc50 @ 0x0026dc50
struct Worker_26dc50 {
    char pad00[8];
    int value08;
    int value0c;
    Worker_26dc50 *self10;
    int value14;
    int value18;
    int value1c;
    int value20;
    int value24;
    int value28;
    int *link2c;
    int *link30;
    int *link34;
    unsigned char active38;
    char pad39[7];
    int priority40;
    int threadId44;
    void *thread48;
};
extern int DAT_004cd9d0[];
void __cdecl FUN_0026d8f0(Worker_26dc50 *);
unsigned long __stdcall FUN_0026db70(void *);
namespace XAPILIB {
void * __stdcall CreateThread(void *, unsigned long, unsigned long (__stdcall *)(void *), void *, unsigned long, unsigned long *);
int __stdcall SetThreadPriority(void *, int);
}
int __stdcall FUN_0020bd91(void *);
int __cdecl FUN_0026dc50(Worker_26dc50 *worker, int first, int second, int priority, unsigned long stackSize, int unused) {
    worker->active38 = 1;
    worker->link2c = &worker->value08;
    worker->value28 = 0;
    worker->value08 = first;
    worker->value0c = second;
    worker->self10 = worker;
    worker->value1c = 0;
    worker->value20 = 0;
    worker->value24 = 0;
    worker->link30 = &worker->value08;
    worker->value18 = 0;
    worker->link34 = &worker->value08;
    worker->value14 = 0;
    FUN_0026d8f0(worker);
    worker->thread48 = XAPILIB::CreateThread(0, stackSize, FUN_0026db70, worker, 4, (unsigned long *)&worker->threadId44);
    worker->value24 = 0;
    worker->priority40 = priority;
    XAPILIB::SetThreadPriority(worker->thread48, DAT_004cd9d0[priority]);
    return FUN_0020bd91(worker->thread48);
}