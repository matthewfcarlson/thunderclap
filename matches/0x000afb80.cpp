void Refresh();
class Thing_afb80 {
    char pad[8];

  public:
    char value;
    void Update(char);
};
void Thing_afb80::Update(char x) {
    if (value != x)
        Refresh();
    value = x;
}