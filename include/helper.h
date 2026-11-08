#ifndef HELPER_H
#define HELPER_H

// Based on function in P5.js / Processing
static inline float remap(float value, float input_start, float input_stop, float output_start, float output_stop)
{
    return output_start + (output_stop - output_start) * ((value - input_start) / (input_stop - input_start));
}

#endif 