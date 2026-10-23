// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 1/1)
// FUN_0026dc20 @ 0x0026dc20
// equiv-dead: +0x7 not taken: the null-result path dereferences null (faults on every input)
struct Task;
typedef void (__cdecl *TaskFn)(int);

struct Task {
    TaskFn fn;          // 0x00
    int arg;            // 0x04
    char pad8[0x10];
    Task* current;      // 0x18
    char pad1c[0x10];
    Task* owner;        // 0x2c
};

Task* __cdecl FUN_0026dbb0();

void __stdcall FUN_0026dc20(int unused)
{
    Task* t = FUN_0026dbb0();
    Task* o;
    if (t != 0) {
        o = t->owner;
        o->current = 0;
    } else {
        // the original dereferences the null result here (faults); kept as is
        o = t;
        t->current = t;
    }
    o->fn(o->arg + 1);
}
