#include "gen/owners.h"
struct Temp_1eb950 {
    char data[0x48];
    void Add(const char*);
};
struct Manager_1eb950 {
};
struct Obj_1eb950 {
    void Send(Temp_1eb950*, int, float, float);
};
struct Owner_1eb950 {
    char pad[4];
    Manager_1eb950* mgr;
    char enabled;
    void Run(float);
};
void Use(int*, Temp_1eb950*);
void Owner_1eb950::Run(float x) {
    Temp_1eb950 t;
    if (enabled) {
        ((owners::Obj_1ef320 *)&t)->FUN_001ef320();
        t.Add("Objects");
        t.Add("DSP");
        int* p = ((int *)((owners::C_86310 *)mgr)->FUN_00086310());
        if (p)
            Use(p, &t);
        if (enabled)
            ((Obj_1eb950*)*(void**)this)->Send(&t, 0, x, 100.0f);
        ((owners::C_1ef350 *)&t)->FUN_001ef350();
    }
}
