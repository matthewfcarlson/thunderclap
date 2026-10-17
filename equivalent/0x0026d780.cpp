// STATUS: equivalent (tools/equiv.py level 3: 2892 inputs, branch coverage 2/2)
// FUN_0026d780 @ 0x0026d780
struct Task { char pad[0x38]; char busy; char pad2[3]; int result; };
void __stdcall FUN_0020c723(int);
int __cdecl FUN_0026d780(Task* task) {
    while (task->busy != 0) {
        FUN_0020c723(0);
    }
    return task->result;
}
