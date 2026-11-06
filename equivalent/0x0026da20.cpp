// STATUS: equivalent (tools/equiv.py level 3: 2949 inputs, branch coverage 4/4)
// FUN_0026da20 @ 0x0026da20
// The main thread leaves the scheduler: its own fiber off its thread's fiber list, then the thread off the list.
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"

// (class-scope declarations of the TU-mates' C functions: gen_tree gives a merged C definition's other C
// declarations C++ linkage, docs/native-build.md "A gen_tree bug"; bound by the address in the name)
struct ThreadList_26da20 {
    static void __cdecl FUN_0026d940(void *);
};
void FUN_0026da20() {
    CoreThread* head = DAT_0052a130.main.thread;
    if (DAT_0052a130.main.previous == 0) head->first = DAT_0052a130.main.next; else DAT_0052a130.main.previous->next = DAT_0052a130.main.next;
    if (DAT_0052a130.main.next == 0) head->last = DAT_0052a130.main.previous; else DAT_0052a130.main.next->previous = DAT_0052a130.main.previous;
    ThreadList_26da20::FUN_0026d940(&DAT_0052a130);
}
