open Jest;
open Expect;
open ReactTestingLibrary;

open Box;

test("<Box />", () => {
  let result = <Box> "from box"->React.string </Box> |> render;

  //System.make(
  //  ~p=Some(`sc(3)),
  //  ~pt=Some(`sc(3)),
  //  ~pb=Some(`sc(3)),
  //  ~pl=Some(`sc(3)),
  //  ~pr=Some(`sc(3)),
  //  ~py=Some(`sc(3)),
  //  ~px=Some(`sc(3)),
  //)
  //->Js.log;

  //System.make(
  //  ~p=Some(`sc(3)),
  //  ~pt=None,
  //  ~pb=None,
  //  ~pl=None,
  //  ~pr=None,
  //  ~py=None,
  //  ~px=Some(`sc(9)),
  //)
  //->Js.log;

  let element = getByText(~matcher=`Str("from box"), result);

  expect(element) |> toMatchSnapshot;
});