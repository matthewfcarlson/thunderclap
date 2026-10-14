struct S_16eb60 {
    int a;
    int b;
    int c;
};
class C_16eb60 {
  public:
    char pad[0x24];
    int x;
    int y;
    int z;
    bool operator=(S_16eb60* p_16eb60);
};
bool C_16eb60::operator=(S_16eb60* p_16eb60) {
    x = p_16eb60->a;
    y = p_16eb60->b;
    z = p_16eb60->c;
    return true;
}
