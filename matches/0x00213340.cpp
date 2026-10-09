struct S { char pad[8]; int* p; };
void FUN_00213340(S* a, int b) { int* p = a->p; p[1] = b; p[0] = 3; a->p = (int*)((char*)a->p + 8); }