struct T {
    int a, b, c, d;
};
T* __fastcall FUN_00011840(T* self, void* p, int w, int x, int y, int z) {
    self->a = w;
    self->b = x;
    self->c = y;
    self->d = z;
    return self;
}