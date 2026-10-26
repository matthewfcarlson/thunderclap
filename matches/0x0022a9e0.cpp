struct Thing_22a9e0 {
    char pad[0x20];
    int a;
    int b;
    Thing_22a9e0* CopyFrom(Thing_22a9e0*);
    Thing_22a9e0* FUN_00222460(Thing_22a9e0*);
};

Thing_22a9e0* Thing_22a9e0::CopyFrom(Thing_22a9e0* other) {
    FUN_00222460(other);
    a = other->a;
    b = other->b;
    return this;
}
