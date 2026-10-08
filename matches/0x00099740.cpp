class A { public: int pad; unsigned int value; };
unsigned int __fastcall target(A* self) { return (self->value >> 2) & 1; }