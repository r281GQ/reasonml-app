open Jest;
open Expect;
open ReactTestingLibrary;

test("<App />", () => {
  let result = <Box p={`sc(9)}> "from box"->React.string </Box> |> render;

  let element = getByText(~matcher=`Str("from box"), result);

  expect(element) |> toMatchSnapshot;
});