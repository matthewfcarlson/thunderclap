class C {
  public:
    char pad[0x11c];
    int* p;
};
int __fastcall target(C* self) {
    if (!self->p)
        return 0;
    return self->p[6];
}