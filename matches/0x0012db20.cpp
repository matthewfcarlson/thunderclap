// Same code shape as 0x0012bc00 (propagated; names are from that function)
#include "gen/hulkfight.h"
extern char threat_vftable_12db20;
struct PostEvent_StringTrack_nv_12db20 {
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(hulkfight::PostEvent_StringTrack*);
class PostEvent_StringTrack_12db20 {
  public:
    void* vftable;
    char pad[0x0c];
    PostEvent_StringTrack_12db20* vfunc_5(unsigned char);
};
PostEvent_StringTrack_12db20* PostEvent_StringTrack_12db20::vfunc_5(unsigned char param) {
    PostEvent_StringTrack_12db20* p = this;
    *(char**)p = &threat_vftable_12db20;
    ((PostEvent_StringTrack_nv_12db20*)(((hulkfight::PostEvent_StringTrack*)((char*)p + 0x10))))->f1();
    ((PostEvent_StringTrack_nv_12db20*)(((hulkfight::PostEvent_StringTrack*)p)))->f2();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::PostEvent_StringTrack*)p);
    return p;
}