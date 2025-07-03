// moduli
const express = require("express");
const app = express();
const path = require("path");
const session = require("express-session");

app.use(
  session({
    secret: "anything",
    resave: false,
    saveUninitialized: true,
  }),
);

// ruteri
const homeRouter = require("./routes/home.routes");
const quizRouter = require("./routes/quiz.routes");

// setup ejs-a
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

// setup za statičko posluživanje
app.use(express.static(path.join(__dirname, "public")));

// pokretanje rutera
app.use("/", homeRouter);
app.use("/", quizRouter);

// slušanje na portu 8080
const PORT = 8080;
app.listen(PORT, () => {
    console.log(`Listening on port ${PORT}!`);
})