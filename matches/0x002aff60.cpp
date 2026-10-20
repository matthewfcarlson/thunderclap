#include "compat/ptr.h"
extern "C" char DAT_0042e340[];
class ExpressionGroupLoader {
  public:
    hulk_intptr vf;
    int a;
    int b;
    int c;
    int d;
    ExpressionGroupLoader();
};
ExpressionGroupLoader::ExpressionGroupLoader() {
    a = 0;
    b = 0x21001;
    c = 0;
    d = 0;
    vf = ((hulk_intptr)DAT_0042e340);
}