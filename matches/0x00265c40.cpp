struct State { unsigned char p0[1]; unsigned char flag; unsigned char p2[0x12]; int at14; int at18; int at1c; unsigned char p20[4]; int at24; int at28; int at2c; int at30; };
void __cdecl Init(void *);
void __cdecl Release(void *);
void __cdecl Free(void *);
State *g_state;
char g_obj;
void __cdecl FUN_00265c40(void) {
    State *s = g_state;
    s->flag = 1;
    Init((void*)&g_obj);
    int x = s->at30;
    s->at28 = x;
    s->at2c = x;
    if (x) Release((void *)x);
    x = s->at1c;
    s->at14 = x;
    s->at18 = x;
    if (x) Release((void *)x);
    Free(s);
    g_state = 0;
}
