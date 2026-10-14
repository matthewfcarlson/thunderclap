struct Buffer_25cbc0 {
    char data[0x1a4];
};
struct State_25cbc0 {
    void FUN_0023fac0();
    void FUN_00240190(unsigned);
    char data[4];
};
struct SourceTable {
    void(__cdecl* slot0)();
    void(__cdecl* slot1)();
    void(__cdecl* slot2)();
    void(__cdecl* slot3)();
    void(__cdecl* get)(SourceTable*, unsigned*);
    void(__cdecl* set)(SourceTable*, unsigned);
};
struct Source_25cbc0 {
    SourceTable* table;
    void FUN_00246f00(Buffer_25cbc0*, unsigned, unsigned, unsigned);
};
void __cdecl FUN_00263470(Buffer_25cbc0*);
void __cdecl FUN_00263480(unsigned*, Buffer_25cbc0*);
namespace audio {
struct OmHalStream {
    virtual void dummy();
    Source_25cbc0* source;
    unsigned remaining;
    unsigned result;
    Buffer_25cbc0 buffer;
    unsigned zero;
    unsigned option;
    State_25cbc0 state;
    OmHalStream(Source_25cbc0*, unsigned, unsigned, unsigned);
};
} // namespace audio
audio::OmHalStream::OmHalStream(Source_25cbc0* s, unsigned setup, unsigned count, unsigned opt) {
    source = s;
    remaining = count;
    zero = 0;
    option = opt;
    state.FUN_0023fac0();
    state.FUN_00240190(setup);
    unsigned position = 0;
    SourceTable* table = source->table;
    table->get(table, &position);
    source->FUN_00246f00(&buffer, 0x1a4, 0, 1);
    table = source->table;
    table->set(table, position + 0x800);
    remaining -= 0x800;
    FUN_00263470(&buffer);
    FUN_00263480(&result, &buffer);
}