class MultiController {
  public:
    char pad[0x1c];
    float scale;
    char pad20[8];
    float first;
    float second;
    void vfunc_15(float*, float*);
};
void MultiController::vfunc_15(float* a, float* b) {
    *a = first * scale;
    *b = second * scale;
}