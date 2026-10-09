typedef unsigned int uint;
struct Obj { char pad[12]; struct Inner *p; };
struct Inner { char pad[8]; int value; };
void FUN_00220b20(Obj*, uint, int);
void FUN_00220c10(Obj* a, uint b, int c, uint d) { FUN_00220b20(a, (c << 18 | d) << 6 | b, a->p->value); }
