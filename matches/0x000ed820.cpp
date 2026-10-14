class Elem_ed820 {
  public:
    void Init();
    char d[0x24];
};
class Base_ed820 {
  public:
    Base_ed820(int);
    virtual void X();
    char pad[0x14c];
};
class TextTable : public Base_ed820 {
  public:
    virtual void X();
    int m150, m154, m158;
    Elem_ed820 arr[0x200];
    int a, b, c, d;
    float e;
    float f[8];
    TextTable(int);
};
TextTable::TextTable(int x) : Base_ed820(x) {
    for (int i = 0; i < 0x200; i++)
        arr[i].Init();
    m150 = 0;
    m154 = 0;
    m158 = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0.1f;
    for (int j = 0; j < 8; j++)
        f[j] = 1.0f;
}
