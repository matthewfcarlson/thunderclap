#include "compat/ptr.h"
extern "C" char DAT_00400854[];
class CSPHulkPropLoader {
  public:
    virtual ~CSPHulkPropLoader();
    CSPHulkPropLoader* Init();
};
struct ThisCall_00290740 {
    void Initialize();
};
CSPHulkPropLoader* CSPHulkPropLoader::Init() {
    ((ThisCall_00290740*)(this))->Initialize();
    *(void**)this = (void*)((hulk_intptr)DAT_00400854);
    return this;
}