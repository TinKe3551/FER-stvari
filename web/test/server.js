// moduli
const express = require("express");
const app = express();
const path = require("path");
const session = require("express-session");

// ruteri
const homeRouter = require("./routes/home.routes");
const cartRouter = require("./routes/cart.routes");

// setup ejs-a
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

// setup za statičko posluživanje
app.use(express.static(path.join(__dirname, "public")));

// pokretanje rutera
app.use("/", homeRouter);
app.use("/", cartRouter);

app.use(
    session({
        secret: "anything",
        resave: false,
        saveUninitialized: true,
    })
);

app.listen(3000);
