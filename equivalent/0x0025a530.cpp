// STATUS: equivalent (tools/equiv.py level 3: 192 inputs, branch coverage 10/10)
// audio::Mix::vfunc_4 @ 0x0025a530
struct Head_25a530 { char pad[0x10]; };
struct Link_25a530 { char data[0x14]; };
struct Track : Head_25a530, Link_25a530 {
    int f24;
    char pad28[0xc];
    int state;
};
struct List_25a530 { char data[0x10]; };
struct Other_25a530 { char data[4]; };

Link_25a530 *__cdecl FUN_00257ec0(List_25a530 *list);
Link_25a530 *__cdecl FUN_00257ee0(Link_25a530 *l);
void __cdecl FUN_0025a0b0(Track *t);
void __cdecl FUN_0025a220(Other_25a530 *o);
void __cdecl FUN_00242f60(int a, Track *t, int b);

class Mix {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual bool vfunc_4(int arg);
    virtual bool vfunc_5(int arg);
    char pad04[0x24];
    List_25a530 tracks;
    Other_25a530 other;
};

bool Mix::vfunc_4(int arg)
{
    for (Link_25a530 *l = FUN_00257ec0(&tracks); l != 0; l = FUN_00257ee0(l))
        FUN_0025a0b0(static_cast<Track *>(l));
    FUN_0025a220(&other);
    bool result = vfunc_5(arg);
    for (Link_25a530 *l = FUN_00257ec0(&tracks); l != 0; l = FUN_00257ee0(l)) {
        Track *t = static_cast<Track *>(l);
        if (t->state == 2) {
            t->state = 0;
            FUN_00242f60(t->f24, t, 0);
        }
    }
    return result;
}
