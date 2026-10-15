class C {
  public:
    char pad[0x38];
    int Lookup(int id);
    int Get(int id);
};

struct E {
    int v;
    char pad[60];
};

int C::Get(int id) {
    int r = Lookup(id);
    if (r == -1)
        return 0;
    E* p = (E*)((char*)this + 0x38);
    return p[r].v;
}
