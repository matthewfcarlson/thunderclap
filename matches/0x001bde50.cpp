class Thing_1bde50 {
  public:
    char pad[0x34];
    Thing_1bde50* a;
    Thing_1bde50* b;
    char pad2[0x0c];
    int value;
    void Prepare(int);
    void Finish();
    bool Update(int);
};
bool Thing_1bde50::Update(int x) {
    value = x;
    if (a) {
        a->Prepare(x);
        a->Finish();
    }
    if (b) {
        b->Prepare(value);
        b->Finish();
    }
    return true;
}