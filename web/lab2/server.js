// express
const express = require("express");
const app = express();

// ostali moduli
const path = require("path");
const express_session = require("express-session");

// ruteri
const home_router = require("./routes/home.routes");
const cart_router = require("./routes/cart.routes");

// views mapa i ejs
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

// statičko posluživanje datoteka
app.use(express.static(path.join(__dirname, "public")));

// middleware
app.use("/routes", home_router);
app.use("/routes", cart_router);


app.listen(3000);
