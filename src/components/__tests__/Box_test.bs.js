// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var Jest = require("@glennsl/bs-jest/src/jest.js");
var React = require("react");
var ReactTestingLibrary = require("bs-react-testing-library/src/ReactTestingLibrary.bs.js");
var Box$ReactHooksTemplate = require("../Box.bs.js");

Jest.test("<Box />", (function (param) {
        var eta = React.createElement(Box$ReactHooksTemplate.make, {
              p: /* `sc */[
                25744,
                9
              ],
              children: "from box"
            });
        var result = ReactTestingLibrary.render(undefined, undefined, eta);
        console.log(Box$ReactHooksTemplate.System[/* make */1](/* `sc */[
                  25744,
                  3
                ], /* `sc */[
                  25744,
                  3
                ], /* `sc */[
                  25744,
                  3
                ], /* `sc */[
                  25744,
                  3
                ], /* `sc */[
                  25744,
                  3
                ], /* `sc */[
                  25744,
                  3
                ], /* `sc */[
                  25744,
                  3
                ]));
        console.log(Box$ReactHooksTemplate.System[/* make */1](/* `sc */[
                  25744,
                  3
                ], undefined, undefined, undefined, undefined, /* `sc */[
                  25744,
                  9
                ], undefined));
        var element = ReactTestingLibrary.getByText(/* `Str */[
              4153489,
              "from box"
            ], undefined, result);
        return Jest.Expect[/* toMatchSnapshot */16](Jest.Expect[/* expect */0](element));
      }));

/*  Not a pure module */
