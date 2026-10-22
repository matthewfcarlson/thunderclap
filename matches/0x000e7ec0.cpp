class Other {
  public:
    void F();
};
class FEThingsBase_e7ec0 {
  public:
    int Lookup(int a, int b, Other* c);
};
int FEThingsBase_e7ec0::Lookup(int a, int b, Other* c) {
    int result = 0;
    switch (a) {
    case 0xce85a963:
        result = 0;
        break;
    case 0x5ebd3822:
        result = 2;
        break;
    case 0x7e52767b:
        result = 1;
        break;
    default:
        c->F();
        break;
    }
    return result;
}