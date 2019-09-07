/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include <stdio.h>
#include <stdlib.h>

#include "include/c/gr_context.h"
#include "include/c/sk_canvas.h"
#include "include/c/sk_data.h"
#include "include/c/sk_image.h"
#include "include/c/sk_paint.h"
#include "include/c/sk_path.h"
#include "include/c/sk_surface.h"

static sk_surface_t* make_surface(int32_t w, int32_t h) {
    sk_imageinfo_t* info = malloc(sizeof(sk_imageinfo_t));
    *info = (sk_imageinfo_t){ .width = w, .height = h, .colorType = RGBA_8888_SK_COLORTYPE,
                                            .alphaType = PREMUL_SK_ALPHATYPE, .colorspace = NULL };
    return sk_surface_new_raster(info, 0, NULL);
}

static void emit_png(const char* path, sk_surface_t* surface) {
    sk_image_t* image = sk_surface_new_image_snapshot(surface);
    sk_data_t* data = sk_image_encode(image);
    sk_image_unref(image);
    FILE* f = fopen(path, "wb");
    fwrite(sk_data_get_data(data), sk_data_get_size(data), 1, f);
    fclose(f);
    sk_data_unref(data);
}

void draw(sk_canvas_t* canvas) {
    sk_paint_t* fill = sk_paint_new();
    sk_paint_set_color(fill, sk_color_set_argb(0xFF, 0x00, 0x00, 0xFF));
    sk_canvas_draw_paint(canvas, fill);

    sk_paint_set_color(fill, sk_color_set_argb(0xFF, 0x00, 0xFF, 0xFF));
    sk_rect_t rect;
    rect.left = 100.0f;
    rect.top = 100.0f;
    rect.right = 540.0f;
    rect.bottom = 380.0f;
    sk_canvas_draw_rect(canvas, &rect, fill);

    sk_paint_t* stroke = sk_paint_new();
    sk_paint_set_color(stroke, sk_color_set_argb(0xFF, 0xFF, 0x00, 0x00));
    sk_paint_set_antialias(stroke, true);
    sk_paint_set_style(stroke, STROKE_SK_PAINT_STYLE);
    sk_paint_set_stroke_width(stroke, 5.0f);
    sk_path_t* path = sk_path_new();

    sk_path_move_to(path, 50.0f, 50.0f);
    sk_path_line_to(path, 590.0f, 50.0f);
    sk_path_cubic_to(path, -490.0f, 50.0f, 1130.0f, 430.0f, 50.0f, 430.0f);
    sk_path_line_to(path, 590.0f, 430.0f);
    sk_canvas_draw_path(canvas, path, stroke);

    sk_paint_set_color(fill, sk_color_set_argb(0x80, 0x00, 0xFF, 0x00));
    sk_rect_t rect2;
    rect2.left = 120.0f;
    rect2.top = 120.0f;
    rect2.right = 520.0f;
    rect2.bottom = 360.0f;
    sk_canvas_draw_oval(canvas, &rect2, fill);

    sk_path_delete(path);
    sk_paint_delete(stroke);
    sk_paint_delete(fill);
}

int draw_main() {
    sk_surface_t* surface = make_surface(640, 480);
    sk_canvas_t* canvas = sk_surface_get_canvas(surface);
    draw(canvas);
    emit_png("skia-c-example.png", surface);
    sk_surface_unref(surface);
    return 0;
}



int draw_gpu() {
    //const gr_glinterface_t* interface = gr_glinterface_create_native_interface();
    //printf("got interface!");
    printf("making context\n");
    gr_context_t* context = gr_context_make_gl(NULL);

    printf("making rt\n");
    gr_gl_framebufferinfo_t fbInfo;
    fbInfo.fFBOID = 0;
    fbInfo.fFormat = 0x8058; //GR_GL_RGBA8;
    gr_backendrendertarget_t* rt = gr_backendrendertarget_new_gl(640, 800, 0, 8, &fbInfo);
    printf("creating surface props\n");
    sk_surfaceprops_t* props = sk_surfaceprops_new(0, UNKNOWN_SK_PIXELGEOMETRY);
    printf("creating info\n");
    sk_imageinfo_t* info = malloc(sizeof(sk_imageinfo_t));
    *info = (sk_imageinfo_t){ .width = 640, .height = 800, .colorType = RGBA_8888_SK_COLORTYPE,
                                            .alphaType = PREMUL_SK_ALPHATYPE, .colorspace = NULL };
    printf("creating render target\n");
    //sk_surface_t* surface = sk_surface_new_render_target(context, false, info, 1, TOP_LEFT_GR_SURFACE_ORIGIN, props, false);
    sk_surface_t* surface = sk_surface_new_backend_render_target(context, rt, TOP_LEFT_GR_SURFACE_ORIGIN, RGBA_8888_SK_COLORTYPE, NULL, props);
    printf("creating canvas\n");
    if (!surface) {
        printf("Surface is NULL!\n");
    }
    sk_canvas_t* canvas = sk_surface_get_canvas(surface);
    printf("drawing\n");
    draw(canvas);
    printf("flushing\n");
    //gr_context_flush(context);
    sk_canvas_flush(canvas);
    printf("flushed\n");
    return 0;
};
