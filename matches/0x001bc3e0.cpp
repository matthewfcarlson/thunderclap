struct Triple {
    int a, b, c;
};
class Obj {
    char pad[0x330];
    Triple value;

  public:
    Triple Get();
};
Triple Obj::Get() {
    return value;
}