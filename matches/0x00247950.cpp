class C { char pad[0x30]; public: int state; char pad2[4]; int value; };
void f(C* self, int value) { if (self->state == 3 || self->state == 2) { self->state = 1; self->value = value; } }