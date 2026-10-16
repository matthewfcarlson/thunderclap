#include "gen/core.h"

class FileIface {
  public:
    virtual void f0();
    virtual void f1();
};
struct CoreFile {
    char a[4];
    FileIface iface;
    char b[0xc];
    int state;
    char c[0x10c];
    int position;
};

int core::FileGetPositionRequest::vfunc_1() {
    *(*(int * *)&this->f_0c) = (*(CoreFile * *)&this->f_08)->position;
    (*(CoreFile * *)&this->f_08)->iface.f0();
    (*(CoreFile * *)&this->f_08)->state = 0;
    (*(CoreFile * *)&this->f_08)->iface.f1();
    return 1;
}
