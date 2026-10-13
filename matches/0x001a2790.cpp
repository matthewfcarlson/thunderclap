// cl-flags: /O2
struct A {
    char pad[0xdc];
    int value;
};

int __fastcall FUN_001a2790(A* self) {
    return self->value;
}
