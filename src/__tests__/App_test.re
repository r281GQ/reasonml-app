open Jest;
open Expect;
open ReactTestingLibrary;

test("Component renders", () => {
  let result =
    <div style={ReactDOMRe.Style.make(~color="rebeccapurple", ())}>
      <h1> {ReasonReact.string("Heading")} </h1>
    </div>
    |> render;

  let element = getByText(~matcher=`Str("Heading"), result);

  expect(element) |> toMatchSnapshot;
});