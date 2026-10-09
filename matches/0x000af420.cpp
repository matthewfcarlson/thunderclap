extern float thresholds[5];
extern float results[5];
extern const float fallback;
float __cdecl target(float x)
{
 int i=4;
 do {
   if (thresholds[i] <= x) return results[i];
   --i;
 } while(i>=0);
 return fallback;
}
