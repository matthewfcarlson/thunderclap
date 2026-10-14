// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f8a90 @ 0x000f8a90
struct Owner {
    char pad[4];
    struct Names *names;
};
struct Names {
    int FUN_000dfa60(int id);
};

int FUN_000dfcc0(char *dst, int size, const char *fmt, ...);

class NamedValue {
public:
    NamedValue(Owner *o, const char *n) {
        link[0] = link[1] = link[2] = link[3] = 0;
        owner = o;
        FUN_000dfcc0(name, 0x28, "%s", n);
    }
    virtual void v0();
    int link[4];
    Owner *owner;
    char name[0x28];
};

class NamedValueFloat : public NamedValue {
public:
    NamedValueFloat(Owner *o, const char *n, int v, int id);
    virtual void v0();
    int value;
    int shadow;
    int handle;
};

NamedValueFloat::NamedValueFloat(Owner *o, const char *n, int v, int id) : NamedValue(o, n)
{
    shadow = v;
    value = v;
    handle = 0;
    if (id != 0)
        handle = owner->names->FUN_000dfa60(id);
}
