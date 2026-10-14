struct Thing_22a9e0 {
    char pad[0x20];
    int a;
    int b;
    Thing_22a9e0* CopyFrom(Thing_22a9e0*);
};

Thing_22a9e0* Thing_22a9e0::CopyFrom(Thing_22a9e0* other) {
    CopyFrom(other);
    a = other->a;
    b = other->b;
    return this;
}