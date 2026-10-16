extern float limitValue;
extern const float zeroValue;
void __stdcall SetLimit(float v) {
    limitValue = v;
    if (v < zeroValue)
        limitValue = 8.0f;
}