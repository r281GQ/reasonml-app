type scale = [ | `px(int) | `sc(int)];

[@react.component]
let make = (~p: option(scale)=?, ~children) => {
  <div className=Css.(style([padding(px(10))]))> children </div>;
};