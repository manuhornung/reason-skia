open Skia;

let surface = Sk.Surface.makeCanvasSurface("canvas");
let context = CanvasKit.currentContext();
let skCanvas = Sk.Surface.getCanvas(surface);

let paint = Sk.Paint.make();
Sk.Paint.setAntiAlias(paint, true);
Sk.Paint.setColor(paint, Sk.Color.makeARGB(1, 255, 0, 0));
Sk.Paint.setStyle(paint, Stroke);
Sk.Paint.setStrokeWidth(paint, 4.0);

// // This effect smooths out the drawn lines a bit. (TODO: add setPathEffect to bindings)
// paint.setPathEffect(CanvasKit.MakeSkCornerPathEffect(50));

let path = Sk.Path.make();
Sk.Path.moveTo(path, 80, 30);
Sk.Path.lineTo(path, 80, 80);

Sk.Path.moveTo(path, 100, 80);
Sk.Path.lineTo(path, 100, 15);
Sk.Path.lineTo(path, 130, 95);
Sk.Path.lineTo(path, 130, 30);

Sk.Path.moveTo(path, 150, 30);
Sk.Path.lineTo(path, 150, 80);
Sk.Path.moveTo(path, 170, 30);
Sk.Path.lineTo(path, 150, 55);
Sk.Path.lineTo(path, 170, 80);

CanvasKit.setCurrentContext(context);
Sk.Canvas.drawPath(skCanvas, path, paint);
Sk.Canvas.flush(skCanvas);
