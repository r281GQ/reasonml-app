type scale = [ Css.length | `sc(int)];
type marginScale = [ scale | `auto];

type marignResult = [ Css.length | `auto];
type paddingResult = Css.length;

module Theme = {
  let spacing: array(int) = [|4, 8, 12, 16, 24, 32, 48, 72|];

  module System = {
    type padding = {
      top: paddingResult,
      bottom: paddingResult,
      left: paddingResult,
      right: paddingResult,
    };

    type margin = {
      top: marignResult,
      bottom: marignResult,
      left: marignResult,
      right: marignResult,
    };

    let calculate =
        (
          ~main: option([> scale]),
          ~axis: option([> scale]),
          ~individual: option([> scale]),
        )
        : [> scale] => {
      switch (main, axis, individual) {
      | (_, _, Some(exactValue)) => exactValue
      | (_, Some(axisValue), _) => axisValue
      | (Some(mainValue), _, _) => mainValue
      | (_, _, _) => `zero
      };
    };

    let convert: scale => Css.length =
      fun
      | `sc(v) =>
        spacing
        ->Belt.Array.get(v)
        ->Belt.Option.mapWithDefault(`px(v), x => `px(x))
      | #Css.length as x => x;

    let convertMargin: marginScale => [ Css.length | `auto] =
      fun
      | `sc(v) =>
        spacing
        ->Belt.Array.get(v)
        ->Belt.Option.mapWithDefault(`px(v), x => `px(x))
      | `auto as a => a
      | #Css.length as x => x;

    let make =
        (
          ~p: option(scale),
          ~pt: option(scale),
          ~pr: option(scale),
          ~pb: option(scale),
          ~pl: option(scale),
          ~px: option(scale),
          ~py: option(scale),
        ) => {
      let s: padding = {
        top: calculate(~main=p, ~axis=py, ~individual=pt) |> convert,
        bottom: calculate(~main=p, ~axis=py, ~individual=pb) |> convert,
        left: calculate(~main=p, ~axis=px, ~individual=pl) |> convert,
        right: calculate(~main=p, ~axis=px, ~individual=pr) |> convert,
      };

      s;
    };

    let makeMargin =
        (
          ~p: option(marginScale),
          ~pt: option(marginScale),
          ~pr: option(marginScale),
          ~pb: option(marginScale),
          ~pl: option(marginScale),
          ~px: option(marginScale),
          ~py: option(marginScale),
        ) => {
      {
        top: calculate(~main=p, ~axis=py, ~individual=pt) |> convertMargin,
        bottom: calculate(~main=p, ~axis=py, ~individual=pb) |> convertMargin,
        left: calculate(~main=p, ~axis=px, ~individual=pl) |> convertMargin,
        right: calculate(~main=p, ~axis=px, ~individual=pr) |> convertMargin,
      };
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
  let scaleValue = Theme.System.make(~p, ~pt, ~pr, ~pb, ~pl, ~px, ~py);

  let createPadding = (raw: Theme.System.padding) =>
    Css.(
      style([
        raw.top |> paddingTop,
        raw.right |> paddingRight,
        raw.left |> paddingLeft,
        raw.bottom |> paddingBottom,
      ])
    );

  scaleValue |> createPadding;

  <div className=Css.(style([padding(scaleValue.top)]))> children </div>;
};