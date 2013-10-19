var config = module.exports;

config["My tests"] = {
    rootPath: "../",
    environment: "node",
    sources: [
      "src/patients.js"
    ],
    tests: [
      "test/*-test.js"
    ]
};
