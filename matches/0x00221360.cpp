struct Header_221360 {
    char pad[0x47];
    unsigned char maximum;
};
struct Context {
    char pad[8];
    unsigned int value;
};
struct State_221360 {
    Header_221360* header;
    char pad4[8];
    Context* context;
    char pad10[0x14];
    int depth;
    char pad28[0xc];
    unsigned char minimum;
};
struct Operand_221360 {
    int type;
    int value;
};
void __cdecl FUN_00221190(State_221360*, Operand_221360*);
void __cdecl FUN_0021b060(Context*, const char*);
unsigned int __cdecl FUN_00221200(State_221360*, Operand_221360*);
void __cdecl FUN_00220b20(State_221360*, unsigned int, unsigned int);
void __cdecl FUN_00221360(State_221360* state, Operand_221360* destination, Operand_221360* source) {
    FUN_00221190(state, destination);
    if (destination->type == 11 && destination->value >= state->minimum && destination->value < 250)
        --state->depth;
    int oldDepth = state->depth;
    int required = oldDepth + 2;
    if (required > state->header->maximum) {
        if (required >= 250)
            FUN_0021b060(state->context, "function or expression too complex");
        state->header->maximum = (unsigned char)required;
    }
    state->depth += 2;
    unsigned int result = FUN_00221200(state, source);
    unsigned int contextValue = state->context->value;
    unsigned int instruction =
        ((((unsigned int)oldDepth << 9) | (unsigned int)destination->value) << 9 | result) << 6 | 11;
    FUN_00220b20(state, instruction, contextValue);
    if (source->type == 11 && source->value >= state->minimum && source->value < 250)
        --state->depth;
    destination->value = oldDepth;
    destination->type = 11;
}
