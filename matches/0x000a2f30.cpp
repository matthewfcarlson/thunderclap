struct Local_a2f30 {
    char pad[12];
};
struct Helper_a2f30 {
    bool Read(Local_a2f30*);
};
struct CChaseCamera_a2f30 {
    char pad[0x350];
    Helper_a2f30* field;
    void Apply(float, int);
    void Run(int);
};
extern float __cdecl GetVal(Local_a2f30*);
extern float __cdecl Transform(float);
void CChaseCamera_a2f30::Run(int arg) {
    Local_a2f30 local;
    if (field && field->Read(&local)) {
        float x = GetVal(&local);
        x = Transform(x + 180.0f);
        Apply(x, arg);
    }
}
