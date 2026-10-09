struct Callback { virtual void A(); virtual void B(); };
void Init(int);
extern int g;
struct X { void* v0; void* v1; int value; char pad[12]; Callback* cb; int gap; int arg; void F(); };
void X::F() { v0=(void*)0x42afd4; v1=(void*)0x42afcc; Init(arg); cb->B(); g=value; v1=(void*)0x42af64; v0=(void*)0x3f6098; }