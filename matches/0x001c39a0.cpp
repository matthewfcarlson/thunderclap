// Same code shape as 0x001c3990 (propagated; names are from that function)
struct X { char pad[0x1c]; }; 
void* __fastcall target(X* p) { return p->pad + 0x1c; }