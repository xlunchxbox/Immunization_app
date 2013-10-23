"use strict";

// test post with:
// curl --data "user=test&password=test" -b ./cookies.txt -c ./cookies.txt localhost:3000/login
// curl -b ./cookies.txt -c ./cookies.txt  localhost:3000/patients

exports.Server = function () {

  var express = require('express');
  var patientsLib = require('./routes/patients');

  var app = express();
  var patients = new patientsLib.Patients();

  app.configure(function () {
    app.use(express.logger('dev'));
    app.use(express.bodyParser());
    app.use(express.cookieParser());
    app.use(express.session({secret: 'PATIENTRECORDS2'}));
  });

  patients.initDB();

  app.post('/login', patients.login);
  app.post('/logout', patients.logout);

  app.get('/patients', patients.checkAuth, patients.findAllPatients);
  app.get('/patients/:id', patients.checkAuth, patients.findPatientById);
  app.post('/patients', patients.checkAuth, patients.addPatient);
  app.put('/patients/:id', patients.checkAuth, patients.updatePatient);
  app.delete('/patients/:id', patients.checkAuth, patients.deletePatient);

  app.post('/search', patients.checkAuth, patients.searchPatient);
  app.post('/patients/search', patients.checkAuth, patients.searchPatient);


  app.listen(3000);
  console.log('Listening on port 3000...');

};

var testServer = new exports.Server();
