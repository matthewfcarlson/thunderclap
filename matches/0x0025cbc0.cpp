struct Buffer {
    char data[0x1a4];
};
struct State {
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
struct Source {
    SourceTable* table;
    void FUN_00246f00(Buffer*, unsigned, unsigned, unsigned);
};
void __cdecl FUN_00263470(Buffer*);
void __cdecl FUN_00263480(unsigned*, Buffer*);
namespace audio {
struct OmHalStream {
    virtual void dummy();
    Source* source;
    unsigned remaining;
    unsigned result;
    Buffer buffer;
    unsigned zero;
    unsigned option;
    State state;
    OmHalStream(Source*, unsigned, unsigned, unsigned);
};
} // namespace audio
audio::OmHalStream::OmHalStream(Source* s, unsigned setup, unsigned count, unsigned opt) {
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