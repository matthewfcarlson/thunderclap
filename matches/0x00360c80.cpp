#include "decls/data/engine/audio.h"

extern "C" int atexit(void (*)());
struct SeqEventLogicRepeatType_360c80 {
    void F();
};
extern void Cleanup();
void FUN_00360c80() {
    (*(SeqEventLogicRepeatType_360c80*)&DAT_004e73a8).F();
    atexit((void (*)())Cleanup);
}
