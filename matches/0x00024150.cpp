struct Sub { void Helper(); };
struct Owner { char pad[0x40]; void Func(); };
void Owner::Func() { Sub* p=(Sub*)((char*)this+0x48); p->Helper(); p=(Sub*)((char*)this+0x40); p->Helper(); }