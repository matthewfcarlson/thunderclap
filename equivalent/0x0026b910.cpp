// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0026b910 @ 0x0026b910
#include "decls/data/records.h"

// equiv-conv: FUN_0026b910 eax
extern "C" void FUN_0026b910(void * state_) {
    DlHeapState * state = (DlHeapState *)state_;
    for (int i = 0; i < 127; ++i) {
        DlHeapChunk * bin = (DlHeapChunk *)((char *)&state->bins[2 * i + 2] - DlHeapChunk::kHeader);
        bin->next = bin;
        bin->previous = bin;
    }
    state->topPad = 0;
    state->mmapMax = 0;
    state->mmapThreshold = 0x20000;
    state->trimThreshold = 0x20000;
    state->maxFast = (state->maxFast & 2) | 9;
    state->top = (DlHeapChunk *)&state->bins[0];
    state->pageSize = 0x1000;
}
