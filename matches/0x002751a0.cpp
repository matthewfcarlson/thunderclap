#include "compat/ptr.h"
extern "C" char DAT_0042ba80[];
class FileCommitRequest {
  public:
    hulk_intptr vt;
    void Init(int);
    FileCommitRequest(int);
};
extern void __stdcall Finish();
FileCommitRequest::FileCommitRequest(int a) {
    Init(a);
    vt = ((hulk_intptr)DAT_0042ba80);
    Finish();
}