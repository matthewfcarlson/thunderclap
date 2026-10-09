class Ref {
  public:
    virtual void F0();
    virtual void F1();
};
struct Shader {
    char pad[0x80];
    Ref* member;
    void Target();
    void Next();
};
void Shader::Target() {
    *(unsigned long*)this = 0x43386c;
    if (member)
        member->F1();
    Next();
}
