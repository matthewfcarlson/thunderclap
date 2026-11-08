#include "compat/ptr.h"
#include "gen/core.h"

// the request's drive: the drive of the object it works on (an instance drive or a file: their +0xc word, after
// two vftables and the reference count)
struct Owner_2743e0 {
    const void* vftable;
    const void* vftableMutable;
    int refs;
    void* drive;
};
hulk_intptr core::DriveRequest::vfunc_3() {
    return (hulk_intptr)((Owner_2743e0*)this->f_08)->drive;
}
