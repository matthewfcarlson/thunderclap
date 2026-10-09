struct S { char pad[16]; float x; };
float __cdecl FUN_002f2900(S* a, S* b) { float t = b->x; float q = a->x; if (!(q < t)) q = t; return q; }
