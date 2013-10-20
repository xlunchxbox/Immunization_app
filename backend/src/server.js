"use strict";

exports.Server = function () {

  var express = require('express'),
      patientsLib = require('./routes/patients');

  var app = express();
  var patients = new patientsLib.Patients();

  app.configure(function () {
    app.use(express.logger('dev'));
    app.use(express.bodyParser());
    app.use(express.cookieParser());
    app.use(express.session({secret: 'PATIENTRECORDS'}));
  });

  app.post('/login', patients.login);
  app.post('/logout', patients.logout);

  app.get('/patients', patients.checkAuth, patients.findAll);
  app.get('/patients/:id', patients.checkAuth, patients.findById);
  app.post('/patients', patients.checkAuth, patients.addPatient);
  app.put('/patients/:id', patients.checkAuth, patients.updatePatient);
  app.delete('/patients/:id', patients.checkAuth, patients.deletePatient);

  app.listen(3000);
  console.log('Listening on port 3000...');

};



var testServer = new exports.Server();
