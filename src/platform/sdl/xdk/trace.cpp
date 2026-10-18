// The XDK import shim's call log (xdk_shim.h).
#include "xdk_shim.h"

extern "C" {
hulk_xdk_log_fn hulk_xdk_log_sink = 0;

static const char* hulk_xdk_names_[256];
static hulk_u32* hulk_xdk_counts_[256];
static hulk_u32 hulk_xdk_seen_;

void hulk_xdk_trace(const char* name, hulk_u32* calls) {
    hulk_u32 n = ++*calls;
    if (n == 1 && hulk_xdk_seen_ < 256) {
        hulk_xdk_names_[hulk_xdk_seen_] = name;
        hulk_xdk_counts_[hulk_xdk_seen_] = calls;
        hulk_xdk_seen_++;
    }
    if (hulk_xdk_log_sink && (n & (n - 1)) == 0)
        hulk_xdk_log_sink(name, n);
}

hulk_u32 hulk_xdk_called(const char** names, hulk_u32* calls, hulk_u32 max) {
    hulk_u32 i;
    for (i = 0; i < hulk_xdk_seen_ && i < max; i++) {
        if (names)
            names[i] = hulk_xdk_names_[i];
        if (calls)
            calls[i] = *hulk_xdk_counts_[i];
    }
    return hulk_xdk_seen_;
}
}
