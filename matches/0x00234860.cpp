extern "C" char DAT_004279fc[];
extern "C" char DAT_00427a18[];
struct Member_234860 {
    void Init(int);
};
struct ParamValueBool {
    char pad[8];
    ParamValueBool* Build(int);
};
ParamValueBool* ParamValueBool::Build(int value) {
    *(int*)this = ((int)DAT_004279fc);
    ((Member_234860*)((char*)this + 8))->Init(value);
    *(int*)this = ((int)DAT_00427a18);
    return this;
}