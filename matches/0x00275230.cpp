#include "compat/ptr.h"
extern "C" char DAT_0042baa0[];
typedef unsigned int u32_275230;
class FileRequest_275230 {
  public:
    int pad[3];
    FileRequest_275230(u32_275230);
};
extern void Finish();
class FileReadRequest : public FileRequest_275230 {
  public:
    int a, b, c;
    FileReadRequest(u32_275230, u32_275230, u32_275230, u32_275230);
};
FileReadRequest::FileReadRequest(u32_275230 x, u32_275230 y, u32_275230 z, u32_275230 w) : FileRequest_275230(x) {
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042baa0);
    a = y;
    b = z;
    c = w;
    Finish();
}