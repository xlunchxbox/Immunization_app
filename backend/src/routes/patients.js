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

  this.login = function(req, res) {
    var post = req.body;
    if (post && post.user && post.password) {
      //console.log("Username: " + post.user + ", Password: " + post.password);
      if (authenticateUser(post.user, post.password)) {
        req.session.user_id = post.user;
        res.send('{status: "success"}');
      } else {
        res.send('{status: "failure"}');
      }
    } else {
      res.send('{status: "failure"}');
    }
  };

  this.logout = function(req, res) {
    delete req.session.user_id;
    res.send('{status: "success"}');
  };

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

  this.checkAuth = function(req, res, next) {
    if (req.session.user_id) {
      res.header('Cache-Control', 'no-cache, private, no-store, must-revalidate, max-stale=0, post-check=0, pre-check=0');
      next();
    } else {
      console.log(req.session.user_id);
      res.send('You are not authorized to view this page');
    }
  };

  var authenticateUser = function(username, password) {
    for (var user in authenticatedUsers) {
      if (authenticatedUsers[user].username === username && authenticatedUsers[user].password === password)
        return true;
    }
    return false;
  };

  var authenticatedUsers = [{
    firstName: "Frauline",
    lastName: "Gerberitz",
    username: "test",
    password: "test"
  }];
};

var populateDB = function() {
  var patients = [{
    firstName: "John",
    middleName: "Arnold",
    lastName: "Smith",
    birthYear: "1992",
    birthMonth: "11",
    birthDay: "22",
    contactPhone: "12815551234",
    contactEmail: "john.smith@gmail.com",
    picture: "john1.jpg"
  }, {
    firstName: "Mary",
    middleName: "Ann",
    lastName: "Whistler",
    birthYear: "1997",
    birthMonth: "3",
    birthDay: "2",
    contactPhone: "17135554321",
    contactEmail: "mary.whistler@gmail.com",
    picture: "mary1.jpg"
  }];

  db.collection('patients', function(err, collection) {
    collection.insert(patients, {
      safe: true
    }, function(err, result) {});
  });

};
