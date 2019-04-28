open Webapi.Dom;

let handleClickOutside = (domElement: Dom.element, e: Dom.mouseEvent, fn) => {
  let el = MouseEvent.currentTarget(e)->EventTarget.unsafeAsElement;
  Element.contains(domElement, el) ? fn(e) : ();
};

let useClickOutside = (onClickOutside: Dom.mouseEvent => unit) => {
  let elementRef = React.useRef(Js.Nullable.null);

  let handleMouseDown = (e: Dom.mouseEvent) => {
    elementRef
    ->React.Ref.current
    ->Js.Nullable.toOption
    ->Belt.Option.map(refValue =>
        handleClickOutside(refValue, e, onClickOutside)
      )
    ->ignore;
  };

  React.useEffect0(() => {
    Document.addMouseDownEventListener(handleMouseDown, document);
    // cleanup - unsubscribe on umnount.
    Some(
      () => Document.removeMouseDownEventListener(handleMouseDown, document),
    );
  });

  elementRef;
};
