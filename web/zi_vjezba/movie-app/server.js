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
    cookie: {
      maxAge: 3600000,
    },
  }),
);

// ruteri
const homeRouter = require("./routes/home.routes");
const movieRouter = require("./routes/movie.routes");

// setup ejs-a
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

// setup za statičko posluživanje
app.use(express.static(path.join(__dirname, "public")));

// pokretanje rutera
app.use("/", homeRouter);
app.use("/", movieRouter);

console.log("server open on localhost:3000");
app.listen(3000);
