"use strict";

var mongo = require('mongodb');

var Server = mongo.Server,
  Db = mongo.Db,
  BSON = mongo.BSONPure;

var server = new Server('localhost', 27017, {
  auto_reconnect: true
});

var db = new Db('patientdb', server, {
  safe: true
});

db.open(function(err, db) {
  if (!err) {
    console.log("Connected to 'patientdb' database");
    db.collection('patients', {
      strict: true
    }, function(err, collection) {
      if (err) {
        console.log("The 'patients' collection doesn't exist. Creating it with sample data...");
        populateDB();
      }
    });
  }
});



exports.Patients = function() {



  this.findAll = function(req, res) {
    db.collection('patients', function(err, collection) {
      collection.find().toArray(function(err, items) {
        res.send(items);
      });
    });
  };

  this.findById = function() {};
  this.addPatient = function() {};
  this.updatePatient = function() {};
  this.deletePatient = function() {};
  this.populateDB = function() {};



};

var populateDB = function() {
  var patients = [{
    firstName: "John",
    middleName: "Arnold",
    lastName: "Smith",
    birthYear: "1992",
    birthMonth: "11",
    birthDay: "22",
    contactPhone: "Grenache / Syrah",
    contactEmail: "France",
    picture: "john1.jpg"
  }, {
    firstName: "John",
    middleName: "Arnold",
    lastName: "Smith",
    birthYear: "1992",
    birthMonth: "11",
    birthDay: "22",
    contactPhone: "Grenache / Syrah",
    contactEmail: "France",
    picture: "john1.jpg"
  }];

  db.collection('patients', function(err, collection) {
    collection.insert(patients, {
      safe: true
    }, function(err, result) {});
  });

};
