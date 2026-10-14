extern "C" char DAT_0043386c[];
class Ref_32a3d0 {
  public:
    virtual void F0();
    virtual void F1();
};
struct Shader {
    char pad[0x80];
    Ref_32a3d0* member;
    void Target();
    void Next();
};
void Shader::Target() {
    *(unsigned long*)this = ((int)DAT_0043386c);
    if (member)
        member->F1();
    Next();
}
