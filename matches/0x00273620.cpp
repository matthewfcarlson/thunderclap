// Same code shape as 0x001cc840 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/core.h"
// the request's drive (0x00274ba0 stores it at +0xc)
hulk_intptr core::CompletionEventRequest::vfunc_3() {
    return (hulk_intptr)(this->f_0c);
}
