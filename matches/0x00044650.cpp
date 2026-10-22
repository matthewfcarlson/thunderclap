struct Vec {
    float x, y, z;
    Vec() : x(0.0f), y(0.0f), z(0.0f) {}
};
class CCharacter_44650 {
    char pad[0xa4];
    Vec elems[1];

  public:
    Vec* Get(int n);
};
Vec* CCharacter_44650::Get(int n) {
    static Vec zero;
    if (n == 0)
        return &zero;
    return &elems[n];
}