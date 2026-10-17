// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0024c090 @ 0x0024c090
struct Task { char pad[0xc0]; int active; int state; }; 
// equiv-conv: FUN_0024bc70 eax
void FUN_0024bc70(Task* task);
void __cdecl FUN_0024c090(Task* task) {
    task->active = 1;
    do {
        FUN_0024bc70(task);
    } while (task->state == 3);
}