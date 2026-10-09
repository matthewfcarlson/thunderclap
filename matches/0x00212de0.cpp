class Thing { public: char pad[8]; int end; };
int* __fastcall Find(int, Thing*);
void __cdecl Remove(Thing* a, int b) { int* p = Find(b, a); p += 2; while (p < (int*)a->end) { int* q = p - 2; *q = p[0]; q[1] = p[1]; p += 2; } a->end -= 8; }
