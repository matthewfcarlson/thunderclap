/* Kernel imports (xboxkrnl ordinals, the public export list): the XBE's import table points at KERNEL_FN + ordinal
 * (boot.c), so a call through it lands here with the arguments where x86 had them (stdcall). */
#include <stdio.h>
#include "hulk_host.h"
#include "sim.h"

/* RTL_CRITICAL_SECTION (the game's memory): +16 lock count, +20 recursion count, +24 owning thread. Threads are
 * cooperative (sched.c), so a section another thread holds is waited out by sleeping. */
static void cs_init(uint32_t* cs) {
    memset(cs, 0, 28);
    cs[4] = (uint32_t)-1;
}
static void cs_enter(uint32_t* cs) {
    while (cs[6] && cs[6] != SIM->cur_thread) ff_sleep(1);
    cs[6] = SIM->cur_thread;
    cs[5]++;
    cs[4]++;
}
static void cs_leave(uint32_t* cs) {
    if (--cs[5] == 0) cs[6] = 0;
    cs[4]--;
}

void ff_kernel(uint32_t ord, uint32_t ecx, uint32_t edx, void* st, void* rb) {
    (void)ecx; (void)edx;
    switch (ord) {
    case 291: cs_init(PTR(ARG(0))); return;            /* RtlInitializeCriticalSection */
    case 277: cs_enter(PTR(ARG(0))); return;           /* RtlEnterCriticalSection */
    case 294: cs_leave(PTR(ARG(0))); return;           /* RtlLeaveCriticalSection */
    default:
        (void)rb;
        ff_fatal("kernel import %u not implemented", ord);
    }
}
