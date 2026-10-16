struct Triple {
    int a, b, c;
};
class Obj {
    char pad[0xc8];
    Triple value;

  public:
    Triple* Get(Triple* out);
};
Triple* Obj::Get(Triple* out) {
    *out = value;
    return out;
}