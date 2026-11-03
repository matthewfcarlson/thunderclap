extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Obj_26e600 {
  public:
    void Helper(void*, unsigned int);
    void Target(unsigned int, char*);
};
void Obj_26e600::Target(unsigned int id, char* message) {
    struct Local {
        unsigned int a;
        unsigned int b;
        char text[83];
        char end;
    } local;
    local.a = 7;
    local.b = id;
    strncpy(local.text, message, 0x54);
    local.end = 0;
    Helper(&local, 0x5c);
}