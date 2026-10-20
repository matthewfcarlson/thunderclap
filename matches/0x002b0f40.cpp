#include "compat/ptr.h"
extern int g_vtable_2b0f40;
class VertexOffsetExpressionMixerLoader {
  public:
    hulk_intptr m0;
    int m4;
    int m8;
    int mC;
    int m10;
    VertexOffsetExpressionMixerLoader();
};
VertexOffsetExpressionMixerLoader::VertexOffsetExpressionMixerLoader() {
    m4 = 0;
    m8 = 0x21002;
    mC = 0;
    m10 = 0;
    m0 = (hulk_intptr)&g_vtable_2b0f40;
}