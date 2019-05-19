module Gr = {
  module GLInterface = {
    type t;
  };

  module Context = {
    type t;

    external makeGL: option(GLInterface.t) => t = "caml_GrContext_MakeGL";
  };
};

module CanvasKit = {
  type context;
  external currentContext: unit => context = "caml_CanvasKit_currentContext";
  external setCurrentContext: context => unit =
    "caml_CanvasKit_setCurrentContext";
};

module Sk = {
  type scalar = float;

  type point = (scalar, scalar);
  type vector = point;

  type budgeted =
    | No
    | Yes;

  module Color = {
    type t;

    external makeARGB: (int, int, int, int) => t = "caml_SkColor_make";
  };

  module Matrix = {
    type t;
  };

  module Path = {
    type t;
    external make: unit => t = "caml_SkPath_make";
    // external copy: t => t = "caml_SkPath_copy";

    external moveTo: (t, int, int) => unit = "caml_SkPath_moveTo";
    external lineTo: (t, int, int) => unit = "caml_SkPath_lineTo";
  };

  type flattenableType =
    | ColorFilter
    | Drawable
    | DrawLooper
    | ImageFilter
    | MaskFilter
    | PathEffect
    | PixelRef
    | ShaderBase
    | NormalSource;

  type blurStyle =
    | Normal
    | Solid
    | Outer
    | Inner;

  module MaskFilter = {
    type t;

    external makeBlur: (blurStyle, scalar) => t = "caml_SkMaskFilter_MakeBlur";
  };

  module Shader = {
    type t;

    type gradientType =
      | None
      | Color
      | Linear
      | Radial
      | Sweep
      | Conical;

    type tileMode =
      | Clamp
      | Repeat
      | Mirror
      | Decal;
  };

  module Paint = {
    type t;

    type cap =
      | Butt
      | Round
      | Square;

    type join =
      | Miter
      | Round
      | Bevel;

    type style =
      | Fill
      | Stroke
      | StrokeAndFill;

    external make: unit => t = "caml_SkPaint_make";
    // external shallowCopy: t => t = "caml_SkPaint_shallowCopy";
    // external reset: t => unit = "caml_SkPaint_reset";

    external setColor: (t, Color.t) => unit = "caml_SkPaint_setColor";
    external getColor: t => Color.t = "caml_SkPaint_getColor";
    external setStyle: (t, style) => unit = "caml_SkPaint_setStyle";
    external getStyle: t => style = "caml_SkPaint_getStyle";
    external setStrokeWidth: (t, scalar) => unit =
      "caml_SkPaint_setStrokeWidth";
    external getStrokeWidth: t => scalar = "caml_SkPaint_getStrokeWidth";
    external setStrokeCap: (t, cap) => unit = "caml_SkPaint_setStrokeCap";
    external getStrokeCap: t => cap = "caml_SkPaint_getStrokeCap";
    external setStrokeJoin: (t, join) => unit = "caml_SkPaint_setStrokeJoin";
    external getStrokeJoin: t => join = "caml_SkPaint_getStrokeJoin";
    external setStrokeMiter: (t, scalar) => unit =
      "caml_SkPaint_setStrokeMiter";
    external getStrokeMiter: t => scalar = "caml_SkPaint_getStrokeMiter";
    external setAntiAlias: (t, bool) => unit = "caml_SkPaint_setAntiAlias";
    external isAntiAlias: t => bool = "caml_SkPaint_isAntiAlias";
    external setMaskFilter: (t, MaskFilter.t) => unit =
      "caml_SkPaint_setMaskFilter";
    external getMaskFilter: t => MaskFilter.t = "caml_SkPaint_getMaskFilter";
  };

  module Typeface = {
    type t;

    external makeDefault: unit => t = "caml_SkTypeface_MakeDefault";
  };

  module Font = {
    type t;

    type edging =
      | Alias
      | AntiAlias
      | SubpixelAntiAlias;

    external make: (Typeface.t, scalar, scalar, scalar) => t =
      "caml_SkFont_Make";

    external setSubpixel: (t, bool) => unit = "caml_SkFont_setSubpixel";
    external isSubpixel: t => bool = "caml_SkFont_isSubpixel";
    external setEdging: (t, edging) => unit = "caml_SkFont_setEdging";
    external getEdging: t => edging = "caml_SkFont_getEdging";
  };

  type textEncoding =
    | UTF8
    | UTF16
    | UTF32
    | GlyphID;

  type fontHinting =
    | None
    | Slight
    | Normal
    | Full;

  module TextBlob = {
    type t;

    external makeFromString: (string, Font.t, option(textEncoding)) => t =
      "caml_SkTextBlob_MakeFromString";
  };

  module Rect = {
    type t;

    external makeLTRB: (scalar, scalar, scalar, scalar) => t =
      "caml_SkRect_MakeLTRB";
    external makeXYWH: (scalar, scalar, scalar, scalar) => t =
      "caml_SkRect_MakeXYWH";
  };

  module RRect = {
    type t;

    type rRectType =
      | Empty
      | Rect
      | Oval
      | Simple
      | NinePatch
      | Complex;

    external makeRect: Rect.t => t = "caml_SkRRect_MakeRect";
    external makeOval: Rect.t => t = "caml_SkRRect_MakeOval";
    external makeRectXY: (Rect.t, scalar, scalar) => t =
      "caml_SkRRect_MakeRectXY";
    external setRectRadii:
      (t, Rect.t, (vector, vector, vector, vector)) => unit =
      "caml_SkRRect_setRectRadii";
  };

  module Canvas = {
    type t;

    // external save: t => unit = "caml_SkCanvas_save";
    // external translate: (t, scalar, scalar) => unit =
    //   "caml_SkCanvas_translate";
    // external rotate: (t, scalar, scalar, scalar) => unit =
    //   "caml_SkCanvas_rotate";
    external drawPaint: (t, Paint.t) => unit = "caml_SkCanvas_drawPaint";
    external drawPath: (t, Path.t, Paint.t) => unit = "caml_SkCanvas_drawPath";
    external drawRect: (t, Rect.t, Paint.t) => unit = "caml_SkCanvas_drawRect";
    external drawRRect: (t, RRect.t, Paint.t) => unit =
      "caml_SkCanvas_drawRRect";
    external drawTextBlob: (t, TextBlob.t, scalar, scalar, Paint.t) => unit =
      "caml_SkCanvas_drawTextBlob";
    external flush: t => unit = "caml_SkCanvas_flush";
    // external restore: t => unit = "caml_SkCanvas_restore";
  };

  module Size = {
    type t = {
      w: int,
      h: int,
    };
  };

  module ColorSpace = {
    type t;
  };

  type colorType =
    | Unknown
    | Alpha8
    | RGB565
    | ARGB4444
    | RGBA8888
    | RGB888X
    | BGRA8888
    | RGBA1010102
    | RGB101010X
    | Gray8
    | RGBAF16Norm
    | RGBAF16
    | RGBAF32
    | N32;

  type alphaType =
    | Unknown
    | Opaque
    | Premul
    | Unpremul;

  module ImageInfo = {
    type t;

    external make: (int, int, colorType, alphaType, option(ColorSpace.t)) => t =
      "caml_SkImageInfo_Make";
  };

  module Data = {
    type t;
  };

  module FILEWStream = {
    type t;

    external make: string => t = "caml_SkFILEWStream_make";
    external write: (t, Data.t) => unit = "caml_SkFILEWStream_write"; // TODO proper typing and binding
  };

  module Image = {
    type t;

    external encodeToData: t => Data.t = "caml_SkImage_encodeToData";
  };

  type pixelGeometry =
    | Unknown
    | RGBH
    | BGRH
    | RGBV
    | BGRV;

  module SurfaceProps = {
    type t;

    external make: pixelGeometry => t = "caml_SkSurfaceProps_Make";
  };

  module Surface = {
    type t;

    external makeRenderTarget: (Gr.Context.t, budgeted, ImageInfo.t) => t =
      "caml_SkSurface_MakeRenderTarget";

    external makeRaster: (ImageInfo.t, option(SurfaceProps.t)) => t =
      "caml_SkSurface_MakeRaster"; // TODO this should accept an optional SurfaceProps parameter

    external getCanvas: t => Canvas.t = "caml_SkSurface_getCanvas";

    external makeCanvasSurface: string => t =
      "caml_CanvasKit_MakeCanvasSurface";

    external makeImageSnapshot: t => Image.t =
      "caml_SkSurface_makeImageSnapshot";
  };
};
