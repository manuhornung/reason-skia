open Skia;

let createSkiaGraphicsContext = (window: Sdl2.Window.t) => {
  print_endline ("Creating graphics context");
  let interface = Skia.Gr.Gl.Interface.makeSdl2();
  print_endline ("Have interface...");
  let context = Skia.Gr.Context.makeGl(Some(interface));

  switch (context) {
  | None => failwith("Unable to create graphics context");
  | Some(glContext) =>
    print_endline ("glContext created successfully");
    glContext;
  }
};

let run = () => {
  let _ = Sdl2.init();
  /*let attachResult = Sdl2.Platform.win32AttachConsole();

  // If we were unable to attach a console, try allocating a new one
  let _code =
    if (attachResult == 0) {
      Sdl2.Platform.win32AllocConsole();
    } else {
      attachResult;
    };*/

  let primaryWindow = Sdl2.Window.create(100, 100, "test");
  let context = Sdl2.Gl.setup(primaryWindow);

  let skiaContext = createSkiaGraphicsContext(primaryWindow);

  Sdl2.Gl.setSwapInterval(1);

  Sdl2.Window.setTitle(primaryWindow, "reason-skia-sdl2 example");
  Sdl2.Window.setWin32ProcessDPIAware(primaryWindow);

  let scale = Sdl2.Window.getWin32ScaleFactor(primaryWindow);
  let display = Sdl2.Window.getDisplay(primaryWindow);

  Sdl2.Window.setSize(primaryWindow, 800, 600);
  Sdl2.Window.center(primaryWindow);

  Sdl2.Window.show(primaryWindow);

  Sdl2.Window.setResizable(primaryWindow, true);
  Sdl2.Window.setMinimumSize(primaryWindow, 200, 100);

  let frameBufferSize = Sdl2.Gl.getDrawableSize(primaryWindow);
  let render = window => {
    //  glfwMakeContextCurrent(window);
    print_endline("-- Render: start");
    Sdl2.Gl.makeCurrent(window, context);

    print_endline("-- Render: end");
  };

  //let frame = ref(0);
  Sdl2.renderLoop(() => {
    switch (Sdl2.Event.poll()) {
    | None => ()
    | Some(evt) =>
      switch (evt) {
      | Sdl2.Event.Quit => exit(0)
      | _ => ()
      }
    };

    render(primaryWindow);
    Gc.full_major();
    false;
  });

  Lwt.return();
};

run();
