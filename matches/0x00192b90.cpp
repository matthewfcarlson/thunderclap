struct Sub_192b90 {
    char x[176];
};
struct Target_192b90 {
    char pad[0xb0];
    Sub_192b90 sub;
    Sub_192b90* Get();
};
Sub_192b90* Target_192b90::Get() {
    return &sub;
}