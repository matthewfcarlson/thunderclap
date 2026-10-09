class C { char pad[0x10c]; int value; public: int Get(); };
extern void Init(C*, int*);
int C::Get() { if (!value) Init(this, &value); return value; }