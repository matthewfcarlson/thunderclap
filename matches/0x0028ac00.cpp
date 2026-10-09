struct Obj { char pad[0x18]; int *arr; void helper(int, int*, int*); void target(int a, int *out); };
void Obj::target(int a, int *out) { int local; helper(a, &a, &local); *out = arr[a]; }