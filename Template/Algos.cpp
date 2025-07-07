#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

float fisqrt(float n) {
    float y = n;
    float x2 = n * 0.5F;
    int32_t i;

    memcpy(&i, &y, sizeof(float));
    i = 0x5f3759df - (i >> 1);
    memcpy(&y, &i, sizeof(float));

    y *= 1.5F - (x2 * y * y);
    y *= 1.5F - (x2 * y * y);

    return y;
}

