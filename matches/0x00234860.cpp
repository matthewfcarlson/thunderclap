struct Member { void Init(int); };
struct ParamValueBool { char pad[8]; ParamValueBool* Build(int); };
ParamValueBool* ParamValueBool::Build(int value) {
    *(int*)this = 0x4279fc;
    ((Member*)((char*)this + 8))->Init(value);
    *(int*)this = 0x427a18;
    return this;
}