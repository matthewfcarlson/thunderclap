struct Triple {
    int a, b, c;
};
class Obj {
    char pad[0x98];
    Triple v;

  public:
    Triple* Get(Triple* out);
};
Triple* Obj::Get(Triple* out) {
    *out = v;
    return out;
}