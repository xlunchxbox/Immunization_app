Immunization_app
================

2013 Bill &amp; Melinda Gates Immunization App

## Backend API

### /login (Post)

* Request:
  * username
  * password
* Response:
  * status: "success" or "failure"
  * firstName?

### /logout (Post)
* Response:
  * status: "success" or "failure"

### /patients (Get)
Todo

### /search (Post)
* Request:
  * firstName
  * lastName
  * birthMonth
* Response list:
  *  firstName
  *  middleName
  *  lastName
  *  birthYear
  *  birthMonth
  *  birthDay
  *  contactPhone
  *  contactEmail
  *  picture
  *  _id

