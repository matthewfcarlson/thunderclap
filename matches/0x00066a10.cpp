class Obj_66a10 {
  public:
    char pad[0x390];
    int count;
    char pad2[4];
    struct Pair {
        int a, b;
    } entries[150];
    void Base();
    void Add(const int*);
};
void Obj_66a10::Add(const int* p) {
    Base();
    int i = count;
    if (i < 0x96) {
        entries[i].a = p[0];
        entries[i].b = p[1];
        ++count;
    }
}