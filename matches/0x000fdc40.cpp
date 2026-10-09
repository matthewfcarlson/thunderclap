struct Owner {
    char pad0[8];
    int count;
    void* items[1];
};
extern int __cdecl IsType(void*, int, const void*, const void*, int);
extern const int AgentType;
extern const int OccupationAgentType;
int __fastcall Target(Owner* self) {
    int i = 0;
    if (self->count > 0) {
        void** p = self->items;
        do {
            int r = IsType(*p, 0, &AgentType, &OccupationAgentType, 0);
            if (r != 0)
                return r;
            ++i;
            ++p;
        } while (i < self->count);
    }
    return 0;
}