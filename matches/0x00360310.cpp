#include "decls/data/engine/audio.h"
// data: g_mgr_360310 = DAT_004e6bc8

class SeqEventStopTrackType_360310 {
  public:
    void FUN_00250f60();
};


void FUN_00364440() throw() {}

int atexit(void (*)(void));

void FUN_00360310() {
    (*(SeqEventStopTrackType_360310*)&DAT_004e6bc8).FUN_00250f60();
    atexit(FUN_00364440);
}
