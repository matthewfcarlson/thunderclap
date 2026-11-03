#include "gen/owners.h"
struct Inner_863e0 {
    char pad[0x18];
    void f();
};
struct Mid_863e0 {
    char pad[0x18];
    Inner_863e0* p;
};
struct Root_863e0 {
    char pad[0x54];
    Mid_863e0* p;
};
extern Root_863e0* g_863e0;
void owners::Target_863e0::FUN_000863e0(unsigned int x) {
    b = a;
    a = x;
    g_863e0->p->p->f();
}