/* ================================================================== *
 *  Written by Jason Merlo
 *
 *  updates:
 *  11/17/2015
 *
 *  File: bar_matrix.h
 *
 *  Description: Class declarations for bar matrix
 * ================================================================== */

#ifndef BAR_MATRIX_H
#define BAR_MATRIX_H

#include "application.h"
#include "beat_detection.h"
#include "neopixel.h"
#include "muse.h"

#include "math.h"

// constants
#define PI 3.141592

class Bar_Matrix {
    public:
        Bar_Matrix(short num_bars, short bar_len, char led_type, const char* pins, Beat_Detection * beat_detection);

        // General functions
        void
            clear_matrix(),
            tick(audio_bins * bins, int visualizer_type),
            show_all();

        // Misc drawing functions
        void
            bar_test(),
            bouncing_lines(float speed),
            pixel_test(),
            ambient_lighting(Color_Value color);

        // Visualizer drawing functions
        void
            visualizer_bars(audio_bins* bins, float in_factor, float out_factor, bool strobe),
            visualizer_bars_middle(audio_bins* bins, float in_factor, float out_factor),
            visualizer_classic(audio_bins* bins, float in_factor, float out_factor),
            visualizer_plasma(audio_bins* bins, float in_factor, float out_factor),
            visualizer_pulse(audio_bins* bins, float in_factor, float out_factor, float decay_x, float decay_y),
            visualizer_rainbow(audio_bins* bins, float in_factor, float out_factor),
            visualizer_wheel(float intensity, float speed);

    private:
        int bouncing_line_lengths[NUM_BARS];  // Hold the lengths of the bars
        float bouncing_line_positions[NUM_BARS]; // Hold the position of the bottom of the bouncing lines
        int bouncing_line_directions[NUM_BARS]; // Hold the direction each line is moving

        void
            decay(double factor),
            decay_to_rgb(double factor, int r, int g, int b),
            fill_bar(int bar, int r, int g, int b),
            fill_matrix(Color_Value color),
            init_matrix(),
            mix_pixel(unsigned char bar, unsigned short pixel, float factor, unsigned char r, unsigned char g, unsigned char b);
};

const int COLOR_TABLE[50][3] {
  { 25,  50,  75},
  { 50, 100, 150},
  { 75, 150, 225},
  {100, 200,  46},
  {125, 250, 121},
  {150,  46, 196},
  {175,  96,  17},
  {200, 146,  92},
  {225, 196, 167},
  {250, 246, 242},
  { 21,  42,  63},
  { 46,  92, 138},
  { 71, 142, 213},
  { 96, 192,  34},
  {121, 242, 109},
  {146,  38, 184},
  {171,  88,  05},
  {196, 138,  80},
  {221, 188, 155},
  {246, 238, 230},
  { 17,  34,  51},
  { 42,  84, 126},
  { 67, 134, 201},
  { 92, 184,  22},
  {117, 234,  97},
  {142,  30, 172},
  {167,  80, 247},
  {192, 130,  68},
  {217, 180, 143},
  {242, 230, 218},
  { 13,  26,  39},
  { 38,  76, 114},
  { 63, 126, 189},
  { 88, 176,  10},
  {113, 226,  85},
  {138,  22, 160},
  {163,  72, 235},
  {188, 122,  56},
  {213, 172, 131},
  {238, 222, 206},
  {  9,  18,  27},
  { 34,  68, 102},
  { 59, 118, 177},
  { 84, 168, 252},
  {109, 218,  73},
  {134,  14, 148},
  {159,  64, 223},
  {184, 114,  44},
  {209, 164, 119},
  {234, 214, 194}
};

#endif // BAR_MATRIX_H
