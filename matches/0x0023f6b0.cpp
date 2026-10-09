class Target {
  public:
    int pad;
    int value;
};
void __fastcall TargetFn(Target* self) {
    self->value = 1;
}