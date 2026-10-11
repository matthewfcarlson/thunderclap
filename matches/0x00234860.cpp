extern "C" char DAT_004279fc[];
extern "C" char DAT_00427a18[];
struct Member {
    void Init(int);
};
struct ParamValueBool {
    char pad[8];
    ParamValueBool* Build(int);
};
ParamValueBool* ParamValueBool::Build(int value) {
    *(int*)this = ((int)DAT_004279fc);
    ((Member*)((char*)this + 8))->Init(value);
    *(int*)this = ((int)DAT_00427a18);
    return this;
}