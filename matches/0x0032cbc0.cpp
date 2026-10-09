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
    *(void**)this = (void*)0x433a8c;
    a = 0;
    b = 0;
    ((Shader*)((char*)this + 0x88))->InitMember();
    return this;
}