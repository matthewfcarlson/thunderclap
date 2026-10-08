typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(uint);
struct X { int make(void*,void*); };
struct Y { int pad; void* field; void* slots[32]; int f(void*); };
int Y::f(void* p) {
 if (!field) return 0;
 X* x=(X*)FUN_0008d690(0x60);
 int r = x ? x->make(field,p) : 0;
 int i=0;
 do { if (slots[i]==0) { if(r) slots[i]=(void*)r; return r; } ++i; } while(i<32);
 return r;
}
