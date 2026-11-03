#include "gen/owners.h"
struct Temp_25ccf0 {
    char pad[12];
    void Init();
    int Get();
};
unsigned char __cdecl Work(int, Temp_25ccf0*);
struct Receiver_25ccf0 {
    void Send(int);
};
unsigned char Target(int a, Receiver_25ccf0* b) {
    Temp_25ccf0 t;
    t.Init();
    unsigned char r = Work(a, &t);
    if (b)
        b->Send(t.Get());
    ((owners::Str_240060 *)&t)->FUN_00240060();
    return r;
}