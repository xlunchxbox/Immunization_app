"use strict";

exports.Server = function () {

  var express = require('express'),
      patientsLib = require('./routes/patients');

  var app = express();
  var patients = new patientsLib.Patients();

  app.configure(function () {
    app.use(express.logger('dev'));
    app.use(express.bodyParser());
  });

  app.get('/patients', patients.findAll);
  app.get('/patients/:id', patients.findById);
  app.post('/patients', patients.addPatient);
  app.put('/patients/:id', patients.updatePatient);
  app.delete('/patients/:id', patients.deletePatient);

  app.listen(3000);
  console.log('Listening on port 3000...');

};



var testServer = new exports.Server();
