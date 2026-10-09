// Same code shape as 0x0022d210 (propagated; names are from that function)
struct Obj { unsigned int x[3]; void F(Obj*); };
struct Arg { void Helper(Obj*, unsigned int*); };
void Obj::F(Obj* a) { unsigned int t[3]; ((Arg*)a)->Helper(this,t); x[0]=t[0]; x[1]=t[1]; x[2]=t[2]; }