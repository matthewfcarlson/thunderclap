#include "compat/ptr.h"
struct Cache_35630 {
    void* get();
};
struct Result_35630 {
    void run(unsigned int, unsigned int);
};
struct Owner_35630 {
    char pad[16];
    Cache_35630* p;
    bool target(hulk_uintptr a, hulk_uintptr b);
};
bool Owner_35630::target(hulk_uintptr a, hulk_uintptr b) {
    void* x = p->get();
    if (!x)
        return false;
    ((Result_35630*)((char*)x + 16))->run(a, b);
    return true;
}