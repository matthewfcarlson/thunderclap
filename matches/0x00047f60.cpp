class C_47f60 {
  public:
    char pad[0xc];
    int m;
    bool Set(int v) {
        m = v;
        return true;
    }
};

bool __fastcall Target(C_47f60* self, void* eax, int v) {
    self->m = v;
    return true;
}