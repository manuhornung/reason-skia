// Provides: caml_CanvasKit_MakeCanvasSurface
// Requires: caml_to_js_string
function caml_CanvasKit_MakeCanvasSurface(id) {
  var jsId = caml_to_js_string(id);
  return joo_global_object.CanvasKit.MakeCanvasSurface(jsId);
}

// Provides: caml_SkColor_make
function caml_SkColor_make(alpha, red, green, blue) {
  return joo_global_object.CanvasKit.Color(red, green, blue, alpha);
}

// Provides: caml_SkPath_make
function caml_SkPath_make() {
  return new joo_global_object.CanvasKit.SkPath();
}

// Provides: caml_SkPath_moveTo
function caml_SkPath_moveTo(path, x, y) {
  return path.moveTo(x, y);
}

// Provides: caml_SkPath_lineTo
function caml_SkPath_lineTo(path, x, y) {
  return path.lineTo(x, y);
}

// Provides: caml_SkPaint_make
function caml_SkPaint_make() {
  return new joo_global_object.CanvasKit.SkPaint();
}

// Provides: caml_SkPaint_setColor
function caml_SkPaint_setColor(paint, color) {
  return paint.setColor(color);
}

// Provides: caml_SkPaint_getColor
function caml_SkPaint_getColor(paint) {
  return paint.getColor();
}

// Provides: caml_SkPaint_setStyle
function caml_SkPaint_setStyle(paint, style) {
  var PaintStyle = joo_global_object.CanvasKit.PaintStyle;
  var jsStyle;
  switch (style) {
    case 0:
      jsStyle = PaintStyle.Fill;
      break;
    case 1:
      jsStyle = PaintStyle.Stroke;
      break;
    case 2:
      jsStyle = PaintStyle.StrokeAndFill;
      break;
    default:
      throw new TypeError("Unexpected option for style");
  }
  paint.setStyle(jsStyle);
}

// Provides: caml_SkPaint_getStyle
function caml_SkPaint_getStyle(paint) {
  var PaintStyle = joo_global_object.CanvasKit.PaintStyle;
  var jsStyle = paint.getStyle();
  switch (jsStyle) {
    case PaintStyle.Fill:
      return 0;
    case PaintStyle.Stroke:
      return 1;
    case PaintStyle.StrokeAndFill:
      return 2;
    default:
      throw new TypeError("Unexpected value for style option");
  }
}

// Provides: caml_SkPaint_setStrokeWidth
function caml_SkPaint_setStrokeWidth(paint, strokeWidth) {
  return paint.setStrokeWidth(strokeWidth);
}

// Provides: caml_SkPaint_getStrokeWidth
function caml_SkPaint_getStrokeWidth(paint) {
  return paint.getStrokeWidth();
}

// Provides: caml_SkPaint_setStrokeCap
function caml_SkPaint_setStrokeCap(paint, strokeCap) {
  var StrokeCap = joo_global_object.CanvasKit.StrokeCap;
  var jsStrokeCap;
  switch (strokeCap) {
    case 0:
      jsStrokeCap = StrokeCap.Butt;
      break;
    case 1:
      jsStrokeCap = StrokeCap.Round;
      break;
    case 2:
      jsStrokeCap = StrokeCap.Square;
      break;
    default:
      throw new TypeError("Unexpected option for strokeCap");
  }
  paint.setStrokeCap(jsStrokeCap);
}

// Provides: caml_SkPaint_getStrokeCap
function caml_SkPaint_getStrokeCap(paint) {
  var StrokeCap = joo_global_object.CanvasKit.StrokeCap;
  var jsStrokeCap = paint.getStrokeCap();
  switch (jsStrokeCap) {
    case StrokeCap.Butt:
      return 0;
    case StrokeCap.Round:
      return 1;
    case StrokeCap.Square:
      return 2;
    default:
      throw new TypeError("Unexpected value for style strokeCap");
  }
}

// Provides: caml_SkPaint_setStrokeJoin
function caml_SkPaint_setStrokeJoin(paint, strokeJoin) {
  var StrokeJoin = joo_global_object.CanvasKit.StrokeJoin;
  var jsStrokeJoin;
  switch (strokeJoin) {
    case 0:
      jsStrokeJoin = StrokeJoin.Miter;
      break;
    case 1:
      jsStrokeJoin = StrokeJoin.Round;
      break;
    case 2:
      jsStrokeJoin = StrokeJoin.Bevel;
      break;
    default:
      throw new TypeError("Unexpected option for strokeJoin");
  }
  paint.setStrokeJoin(jsStrokeJoin);
}

// Provides: caml_SkPaint_getStrokeJoin
function caml_SkPaint_getStrokeJoin(paint) {
  var StrokeJoin = joo_global_object.CanvasKit.StrokeJoin;
  var strokeJoin = paint.getStrokeJoin();
  switch (strokeJoin) {
    case StrokeJoin.Miter:
      return 0;
    case StrokeJoin.Round:
      return 1;
    case StrokeJoin.Bevel:
      return 2;
    default:
      throw new TypeError("Unexpected value for style strokeJoin");
  }
}

// Provides: caml_SkPaint_setStrokeMiter
function caml_SkPaint_setStrokeMiter(paint, strokeMiter) {
  return paint.setStrokeMiter(strokeMiter);
}

// Provides: caml_SkPaint_getStrokeMiter
function caml_SkPaint_getStrokeMiter(paint) {
  return paint.getStrokeMiter();
}

// Provides: caml_SkPaint_setAntiAlias
function caml_SkPaint_setAntiAlias(paint, antiAlias) {
  return paint.setAntiAlias(antiAlias);
}

// Provides: caml_SkPaint_isAntiAlias
function caml_SkPaint_isAntiAlias(paint) {
  return paint.isAntiAlias();
}

// Provides: caml_SkPaint_setMaskFilter
function caml_SkPaint_setMaskFilter(paint, maskFilter) {
  return paint.setMaskFilter(maskFilter);
}

// Provides: caml_SkPaint_getMaskFilter
function caml_SkPaint_getMaskFilter(paint) {
  return paint.getMaskFilter();
}

// Provides: caml_SkSurface_getCanvas
function caml_SkSurface_getCanvas(surface) {
  return surface.getCanvas();
}

// Provides: caml_SkCanvas_drawPath
function caml_SkCanvas_drawPath(canvas, path, paint) {
  return canvas.drawPath(path, paint);
}

// Provides: caml_SkCanvas_flush
function caml_SkCanvas_flush(canvas) {
  return canvas.flush();
}

// Provides: caml_CanvasKit_currentContext
function caml_CanvasKit_currentContext() {
  return joo_global_object.CanvasKit.currentContext();
}

// Provides: caml_CanvasKit_setCurrentContext
function caml_CanvasKit_setCurrentContext(c) {
  return joo_global_object.CanvasKit.setCurrentContext(c);
}
