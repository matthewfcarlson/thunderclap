extern "C" char DAT_00433c24[];
class Shader {
  public:
    int pad[39];
    void Init(int);
    Shader* Target(int);
};
Shader* Shader::Target(int arg) {
    Init(arg);
    *(void**)this = (void*)((int)DAT_00433c24);
    *(int*)((char*)this + 0x9c) = 0;
    return this;
}