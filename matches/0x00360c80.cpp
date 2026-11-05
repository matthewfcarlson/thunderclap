#include "decls/data/engine/audio.h"

extern "C" int atexit(void (*)());
struct SeqEventLogicRepeatType_360c80 {
    void FUN_00254b10();
};
extern void FUN_003645b0();
void FUN_00360c80() {
    (*(SeqEventLogicRepeatType_360c80*)&DAT_004e73a8).FUN_00254b10();
    atexit((void (*)())FUN_003645b0);
}
