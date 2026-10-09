struct Local {
    char pad[12];
};
struct Helper {
    bool Read(Local*);
};
struct Obj {
    char pad[0x350];
    Helper* field;
    void Apply(float, int);
    void Run(int);
};
extern float __cdecl GetVal(Local*);
extern float __cdecl Transform(float);
void Obj::Run(int arg) {
    Local local;
    if (field && field->Read(&local)) {
        float x = GetVal(&local);
        x = Transform(x + 180.0f);
        Apply(x, arg);
    }
}
