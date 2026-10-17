// STATUS: equivalent (tools/equiv.py level 3: 2980 inputs, branch coverage 4/4)
// FUN_00090200 @ 0x00090200
struct Entry { int value; char rest[60]; };
struct Owner {
    char header[0x38];
    Entry entries[1];
    int FUN_00090130(int value);
    int FUN_00090050(const char *name);
    int FUN_00090200(const char *name, int value);
};
int Owner::FUN_00090200(const char *name, int value)
{
    if (name[0] == 'x' && name[1] == 'p' && name[2] == '\0')
        return FUN_00090130(value);
    int index = FUN_00090050(name);
    if (index != -1) {
        entries[index].value = value;
        return index * 64;
    }
    return index;
}