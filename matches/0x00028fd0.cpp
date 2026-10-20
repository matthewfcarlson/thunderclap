typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int value, int zero1, int zero2);
struct FoundObject;
struct FinalObject {
    FoundObject* FUN_001034e0();
};
struct IntermediateObject {
    FinalObject* FUN_000fdc40();
};
struct FoundObject {
    char pad[0x1ca0];
    IntermediateObject* next;
};
struct Owner {
    FoundObject* FUN_00024280(U64 key);
    FoundObject* FUN_00028fd0(int value);
};
FoundObject* Owner::FUN_00028fd0(int value) {
    U64 key = FUN_002672f0(value, 0, 0);
    FoundObject* found = FUN_00024280(key);
    if (found && found->next) {
        FinalObject* result = found->next->FUN_000fdc40();
        found = (FoundObject*)result;
        if (result)
            found = result->FUN_001034e0();
    }
    return found;
}