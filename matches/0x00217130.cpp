struct Inner { char pad14[0x14]; unsigned char value; char pad15[3]; void* link; };
struct Outer { char pad10[0x10]; Inner* p; };
void FUN_00217130(Outer* a, unsigned char* b, unsigned char c) { Inner* x = a->p; *(void**)b = x->link; x->link = b; b[5] = x->value; b[4] = c; }