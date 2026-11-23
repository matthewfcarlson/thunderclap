// The runner's grass test (wgrass1, docs/grass.md): how much a colour reads as grass or leaves. 1 for green and olive
// vegetation, light or dark (night), 0 for grey asphalt and stone, sand, dirt and blue-tinted surfaces. Shared by the
// reflections' G-buffer (fs_rm_ssrmask.sc: grass stays matte) and the grass blades (grass.cpp's twin, `grassiness`,
// classifies the ground textures and places the blades).
float rmGrassiness(vec3 c)
{
    float s = c.r + c.g + c.b;
    if (s < 0.015)
        return 0.0;                                 // (black: nothing to tell)
    vec3 k = c / s;                                 // chromaticity: brightness (and night) taken out
    // green over red and over blue; olive and brownish leaves (green about red) where blue is low
    float score = (k.g - k.r) + 0.6 * (0.27 - k.b);
    return smoothstep(0.005, 0.035, score) * smoothstep(0.04, 0.08, k.g - k.b);
}
