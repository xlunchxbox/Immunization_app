"use strict";

var buster = require("buster");
var patientsTestModule = require("../src/routes/patients");

buster.testCase("patient unit tests", {

  setUp: function () {
    this.patients = new patientsTestModule.patients(100);
  },

  "Test: Buster Canary" : function () {
    buster.assert(true);
  }




});
