struct Thing {
    char pad[0x20];
    int a;
    int b;
    Thing* CopyFrom(Thing*);
};

Thing* Thing::CopyFrom(Thing* other) {
    CopyFrom(other);
    a = other->a;
    b = other->b;
    return this;
}