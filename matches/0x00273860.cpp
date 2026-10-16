#include "gen/core.h"

class Request_273860 {
  public:
    char pad[8];
    int field;
};

bool core::FileRequest::vfunc_2(int value) {
    return value == (*(int *)&this->f_08);
}
