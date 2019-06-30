type scale = [ Css.length | `sc(int)];
type marginScale = [ scale | `auto];

module Theme = {
  let spacing: array(int) = [|4, 8, 12, 16, 24, 32, 48, 72|];
  module System = {
    // type t = {
    //   top: scale,
    //   bottom: Css.length,
    //   left: Css.length,
    //   right: Css.length,
    // };

    let calculate = (~main, ~axis, ~individual) => {
      switch (main, axis, individual) {
      | (_, _, Some(exactValue)) => exactValue
      | (_, Some(axisValue), _) => axisValue
      | (Some(mainValue), _, _) => mainValue
      | (_, _, _) => `zero
      };
    };

    let make = (~p: option(scale), ~pt, ~pr, ~pb, ~pl, ~px, ~py) => {
      let value =
        calculate(
          ~main=p,
          ~axis=py,
          ~individual=pt,
          // bottom: calculate(~main=p, ~axis=py, ~individual=pb),
          // left: calculate(~main=p, ~axis=px, ~individual=pl),
          // right: calculate(~main=p, ~axis=px, ~individual=pr),
        );

      let g: Css.length =
        switch (value) {
        | `sc(v) =>
          spacing
          ->Belt.Array.get(v)
          ->Belt.Option.mapWithDefault(`px(v), x => `px(x))
        | #Css.length as l => l
        };

      g;
    };
  };
};

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
  // let u =
  //Theme.System.make(~p, ~pt, ~pr, ~pb, ~pl, ~px, ~py);
  let scaleValue = Theme.System.make(~p, ~pt, ~pr, ~pb, ~pl, ~px, ~py);

  <div className=Css.(style([padding(scaleValue)]))> children </div>;
};