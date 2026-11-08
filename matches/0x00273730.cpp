#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"

// the request's drive: its file's (records.h CoreCompletionRequest, CoreFile provider)
hulk_intptr core::FileCompletionRequest::vfunc_3() {
    return (hulk_intptr)((CoreFile*)((CoreCompletionRequest*)this)->file)->provider;
}
