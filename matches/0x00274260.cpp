#include "gen/core.h"

class FileOps {
  public:
    virtual void First();
    virtual void Second();
};
class File_274260 {
  public:
    char pad0[4];
    FileOps ops;
    char pad14[0x14 - 8];
    int state;
    char pad1c[0x128 - 0x18];
    int size;
};

int core::FileGetSizeRequest::vfunc_1() {
    *(*(int * *)&this->f_0c) = (*(File_274260 * *)&this->f_08)->size;
    (*(File_274260 * *)&this->f_08)->ops.First();
    (*(File_274260 * *)&this->f_08)->state = 0;
    (*(File_274260 * *)&this->f_08)->ops.Second();
    return 1;
}
