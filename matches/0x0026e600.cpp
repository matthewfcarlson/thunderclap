extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Obj {
  public:
    void Helper(void*, unsigned int);
    void Target(unsigned int, char*);
};
void Obj::Target(unsigned int param_1, char* param_2) {
    struct Local {
        unsigned int a;
        unsigned int b;
        char text[83];
        char end;
    } local;
    local.a = 7;
    local.b = param_1;
    strncpy(local.text, param_2, 0x54);
    local.end = 0;
    Helper(&local, 0x5c);
}