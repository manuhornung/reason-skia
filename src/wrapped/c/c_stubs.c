/*
 * Use this file for building any C-layer functionality that we want to keep out of Reason
 */

#include "c_stubs.h"

#include <stdlib.h>
#include <stdio.h>


sk_color_t reason_skia_stub_sk_color_set_argb(int alpha, int red, int green, int blue)
{
    return sk_color_set_argb(alpha, red, green, blue);
}

uint32_t reason_skia_stub_sk_color_get_a(sk_color_t color)
{
    return sk_color_get_a(color);
}

uint32_t reason_skia_stub_sk_color_get_r(sk_color_t color)
{
    return sk_color_get_r(color);
}

uint32_t reason_skia_stub_sk_color_get_g(sk_color_t color)
{
    return sk_color_get_g(color);
}

uint32_t reason_skia_stub_sk_color_get_b(sk_color_t color)
{
    return sk_color_get_b(color);
}

void reason_skia_stub_sk_canvas_draw_rect_ltwh(
sk_canvas_t *canvas, float left, float top, float width, float height, sk_paint_t *paint) {
    /*sk_rect_t *rect = (sk_rect_t*)malloc(sizeof(sk_rect_t));
    rect->left = left;
    rect->top = top;
    rect->right = left + width;
    rect->bottom = top + height;*/
    printf("Left: %f top: %f width: %f height: %f\n", left, top, width, height);

    sk_rect_t rect;
    rect.left = 0.0;
    rect.top = 0.0;
    rect.right = 200.0;
    rect.bottom = 200.0;

    sk_canvas_draw_rect(canvas, &rect, paint);
}
