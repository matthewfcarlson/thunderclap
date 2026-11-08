#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"

// the request's drive: its file's (records.h CoreFile provider)
hulk_intptr core::FileRequest::vfunc_3() {
    return (hulk_intptr)((CoreFile*)this->f_08)->provider;
}
