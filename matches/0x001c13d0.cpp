// Same code shape as 0x001c1340 (propagated; names are from that function)
#include "gen/pure3d.h"
struct Child_1c13d0 {
    void First(int);
    void Second();
};
struct Thing_1c13d0 {
    char pad[0xbc];
    Child_1c13d0* volatile child;
    int value;
    void Run();
};
void Thing_1c13d0::Run() {
    child->First(value);
    child->Second();
    ((pure3d::DisplayList *)child)->FUN_0029bba0();
}