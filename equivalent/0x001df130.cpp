// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001df130 @ 0x001df130
struct Object { int FUN_001def30(int); int FUN_001d7100(int); int FUN_001df130(int); };
int Object::FUN_001df130(int value) {
    Object *result = (Object *)FUN_001def30(value);
    if (result) return result->FUN_001d7100(-1);
    return -1;
}