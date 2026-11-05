#include "compat/ptr.h"
struct FileRequest_275390 {
    virtual void Run();
    int dummy;
    FileRequest_275390(int x);
};
struct FileSetPositionRequest : FileRequest_275390 {
    int b;
    int value;
    FileSetPositionRequest(hulk_intptr x, int y);
};
void FinishInit();
FileSetPositionRequest::FileSetPositionRequest(hulk_intptr x, int y) : FileRequest_275390(x) {
    value = y;
    FinishInit();
}
