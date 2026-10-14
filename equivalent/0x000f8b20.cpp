// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f8b20 @ 0x000f8b20
struct Helper_f8b20 { int FUN_000df9e0(const char *s); };
struct Owner_f8b20 { char pad[4]; Helper_f8b20 *helper; };
int __cdecl FUN_000dfcc0(char *buf, int size, const char *fmt, const char *arg);

class NamedValue {
public:
    int f4, f8, fc, f10;
    Owner_f8b20 *owner;
    char name[0x28];
    NamedValue(Owner_f8b20 *o, const char *n)
    {
        f4 = 0;
        f8 = 0;
        fc = 0;
        f10 = 0;
        owner = o;
        FUN_000dfcc0(name, 0x28, "%s", n);
    }
    virtual void v0();
};

class NamedValueInt : public NamedValue {
public:
    int value;
    int value2;
    int helperResult;
    NamedValueInt(Owner_f8b20 *o, const char *n, int v, const char *s);
    virtual void v0();
};

NamedValueInt::NamedValueInt(Owner_f8b20 *o, const char *n, int v, const char *s) : NamedValue(o, n)
{
    value = v;
    value2 = v;
    helperResult = 0;
    if (s != 0)
        helperResult = owner->helper->FUN_000df9e0(s);
}
