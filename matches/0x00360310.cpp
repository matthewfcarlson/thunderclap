#include "decls/data/engine/audio.h"
// data: g_mgr_360310 = DAT_004e6bc8

class SeqEventStopTrackType_360310 {
  public:
    void Run();
};


void Cleanup() throw() {}

int atexit(void (*)(void));

void FUN_00360310() {
    (*(SeqEventStopTrackType_360310*)&DAT_004e6bc8).Run();
    atexit(Cleanup);
}
