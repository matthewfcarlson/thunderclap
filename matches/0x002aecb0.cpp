struct Input;
struct Resource_2aecb0 {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    Resource_2aecb0* FUN_00264430(Input*, int, int);
};
void* __cdecl thunk_FUN_0008d690(unsigned int);
struct Sub_2aecb0 {
    void FUN_0027b040(Input*);
};
struct Result_2aecb0 {
    char pad[8];
    Sub_2aecb0 sub;
};
namespace pure3d {
struct ImageBuilder {
    virtual void slot0();
    Result_2aecb0* result;
    int a, b, c, d;
    int context;
};
} // namespace pure3d
struct Container_2aecb0 {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9(Resource_2aecb0*, pure3d::ImageBuilder*) = 0;
};
struct Owner_2aecb0 {
    char pad[0x8c];
    int context;
    Container_2aecb0* FUN_002ae980(Input*);
    Result_2aecb0* target(Input*);
};
Result_2aecb0* Owner_2aecb0::target(Input* input) {
    Resource_2aecb0* mem = (Resource_2aecb0*)thunk_FUN_0008d690(0x48);
    Resource_2aecb0* r = mem ? mem->FUN_00264430(input, 0, 1) : 0;
    r->slot0();
    Container_2aecb0* c = FUN_002ae980(input);
    if (!c) {
        r->slot1();
        return 0;
    }
    pure3d::ImageBuilder builder;
    builder.result = 0;
    builder.a = 0;
    builder.b = 0;
    builder.c = 0;
    builder.d = 0;
    builder.context = context;
    c->s9(r, &builder);
    Result_2aecb0* result = builder.result;
    if (result)
        result->sub.FUN_0027b040(input);
    r->slot1();
    return result;
}