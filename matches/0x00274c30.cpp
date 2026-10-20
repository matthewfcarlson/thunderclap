#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9dc[];
void init();
class Request {
  public:
    int v;
    int a;
    int b;
};
class CompletionCallbackRequest : public Request {
  public:
    CompletionCallbackRequest(int arg);
};
CompletionCallbackRequest::CompletionCallbackRequest(int arg) {
    v = ((hulk_intptr)DAT_0042b914);
    a = 0;
    init();
    v = ((hulk_intptr)DAT_0042b9dc);
    b = arg;
    init();
}