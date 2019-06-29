type scale = [ | `px(int) | `sc(int) | `zero];

module System = {
  //type t = {
  //  paddingTop: int,
  //  paddingBottom: int,
  //  paddingLeft: int,
  //  paddingRight: int,
  //};

  type t = {
    paddingTop: scale,
    paddingBottom: scale,
    paddingLeft: scale,
    paddingRight: scale,
  };

  let calculate = (~main, ~axis, ~individual) => {
    switch (main, axis, individual) {
    | (_, _, Some(exactValue)) => exactValue
    | (_, Some(axisValue), _) => axisValue
    | (Some(mainValue), _, _) => mainValue
    | (_, _, _) => `zero
    };
  };

  let make = (~p, ~pt, ~pr, ~pb, ~pl, ~px, ~py) => {
    {
      paddingTop: calculate(~main=p, ~axis=py, ~individual=pt),
      paddingBottom: calculate(~main=p, ~axis=py, ~individual=pb),
      paddingLeft: calculate(~main=p, ~axis=px, ~individual=pl),
      paddingRight: calculate(~main=p, ~axis=px, ~individual=pr),
    };
  };
};

// p : padding
// pt: padding-top
// pr: padding-right
// pb: padding-bottom
// pl: padding-left
// px: padding-left and padding-right
// py: padding-top and padding-bottom

[@react.component]
let make =
    (
      ~p: option(scale)=?,
      ~pt: option(scale)=?,
      ~pr: option(scale)=?,
      ~pb: option(scale)=?,
      ~pl: option(scale)=?,
      ~px: option(scale)=?,
      ~py: option(scale)=?,
      ~children,
    ) => {
  System.make(~p, ~pt, ~pr, ~pb, ~pl, ~px, ~py);

  <div className=Css.(style([padding(px(10))]))> children </div>;
};