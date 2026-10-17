// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000bbfa0 @ 0x000bbfa0
struct Values { int first; int second; };
struct Object { void FUN_000b79a0(int first, int second); };
struct Handler { char pad[4]; Object *object; int FUN_000bbfa0(int type, Values *values); };
int Handler::FUN_000bbfa0(int type, Values *values) {
    if (!object || type != 2) return -1;
    object->FUN_000b79a0(values->first, values->second);
    return 0;
}