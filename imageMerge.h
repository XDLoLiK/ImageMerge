/**
 * @defgroup   IMAGEMERGE image Merge
 *
 * @brief      This file implements image Merge.
 *
 * @author     Stanislav
 * @date       2022
 */

#ifndef IMAGE_MERGE_H
#define IMAGE_MERGE_H

#include "SDL2/SDL.h"

#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>
#include <emmintrin.h>
#include <nmmintrin.h>
#include <smmintrin.h>

typedef uint32_t RGBA;

// SDL consts
const int SCREEN_WIDTH  = 800;
const int SCREEN_HEIGHT = 600;

// SSE consts
const __m128i ZERO_M128    =                   _mm_set_epi8(0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0);
const __m128i MAX_NUM_M128 = _mm_cvtepu8_epi16(_mm_set_epi8(255u, 255u, 255u, 255u, 255u, 255u, 255u, 255u, 255u, 255u, 255u, 255u, 255u, 255u, 255u, 255u));

/**
 * @brief      Merges 2 images together
 *
 * @param      mainWindow           The main window
 * @param      backgroungImagePath  The backgroung image path
 * @param      forgroundImagePath   The forground image path
 *
 * @return     The error code
 */
int MergeImages(SDL_Window *mainWindow, char *backgroungImagePath, char *forgroundImagePath);

/**
 * @brief      Updates screen picture
 *
 * @param      surface   The surface
 * @param      renderer  The renderer
 *
 * @return     0
 */
int UpdateScreen(SDL_Surface *surface, SDL_Renderer *renderer);

/**
 * @brief      Calculates the new image
 *
 * @param      backgroungImage  The backgroung image
 * @param      forgroundImage   The forground image
 * @param      outputImage      The output image
 *
 * @return     The new image
 */
int CalculateNewImage(RGBA *backgroungImage, RGBA *forgroundImage, RGBA *outputImage);

#endif // IMAGE_MERGE_H
