extern "C" char DAT_00433a8c[];
class Shader {
  public:
    void InitBase(void*);
    char pad[0x80];
    int a, b;
    void InitMember();
    Shader* Target(void*);
};
Shader* Shader::Target(void* arg) {
    InitBase(arg);
    *(void**)this = (void*)((int)DAT_00433a8c);
    a = 0;
    b = 0;
    ((Shader*)((char*)this + 0x88))->InitMember();
    return this;
}