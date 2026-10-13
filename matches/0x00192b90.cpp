struct Sub {
    char x[176];
};
struct Target {
    char pad[0xb0];
    Sub sub;
    Sub* Get();
};
Sub* Target::Get() {
    return &sub;
}