#include "decls/data/engine/audio.h"
// data: gData_3646d0 = DAT_004e7928

class Obj_3646d0 {
  public:
    void Run();
};
void __stdcall Wrapper() {
    Obj_3646d0* p = (Obj_3646d0*)&(*(int*)((char*)&DAT_004e78e0 + 72));
    p->Run();
}
