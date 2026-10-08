class C { public: int pad; int value; };
void __fastcall Target(C* self) { self->value = 0; }