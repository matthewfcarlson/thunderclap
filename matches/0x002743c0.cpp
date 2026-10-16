// Same code shape as 0x00273860 (propagated; names are from that function)
#include "gen/core.h"

class Request_2743c0 {
  public:
    char pad[8];
    int field;
};

bool core::DriveRequest::vfunc_2(int value) {
    return value == (*(int *)&this->f_08);
}
