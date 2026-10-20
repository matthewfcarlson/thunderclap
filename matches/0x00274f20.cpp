#include "compat/ptr.h"
extern "C" char DAT_0042ba00[];
class FileOpenRequest {
  public:
    hulk_intptr v;
    char pad[8];
    int field;
    unsigned char flag;
    void init(int);
    FileOpenRequest* target(int, int, unsigned char);
};
extern void post();
FileOpenRequest* FileOpenRequest::target(int a, int b, unsigned char c) {
    init(a);
    v = ((hulk_intptr)DAT_0042ba00);
    field = b;
    flag = c;
    post();
    return this;
}