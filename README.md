# Use click outside hook in reason-react

A simple implementation of detecting a click outside of an element encapsulated in a custom hook `useClickOutside`.
It uses react hooks `useRef` and `useEffect` and [`bs-webapi`](https://github.com/reasonml-community/bs-webapi-incubator) that provides bindings to the DOM API.

## Example usage

The hook returns a `ref` that needs to be attached to an element, and takes in a function of type `Dom.mouseEvent => unit` that will be called if a click is detected outside of that element.

Basic usage:

```ocaml
open ClickOutside;

[@react.component]
let make = () => {
  let handleClickOutside = _ => {
    Js.log("Click outside detected");
  };
  let divRef = useClickOutside(handleClickOutside);

  <div ref={ReactDOMRe.Ref.domRef(divRef)} />;
};
```

The repo contains a simple dropdown component to show the usage of the hook. Styling of the dropdown is implemented with the amazing [`bs-css`](https://github.com/SentiaAnalytics/bs-css).

## Run Project

```sh
npm install
npm start
# in another tab
npm run webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up `build/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

## Run Project with Server

To run with the webpack development server run `npm run server` and view in the browser at http://localhost:8000. Running in this environment provides hot reloading and support for routing; just edit and save the file and the browser will automatically refresh.
