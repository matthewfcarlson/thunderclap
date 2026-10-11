extern "C" char DAT_00433eec[];
class BuildingShader {
  public:
    char pad[0x80];
    int a, b, c;
    unsigned char d;
    void BaseCtor(int);
    BuildingShader* Target(int);
};
BuildingShader* BuildingShader::Target(int arg) {
    BaseCtor(arg);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    *(int*)this = ((int)DAT_00433eec);
    return this;
}