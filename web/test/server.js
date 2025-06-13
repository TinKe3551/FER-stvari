// moduli
const express = require("express");
const app = express();
const path = require("path");

// ruteri
const rootRouter = require("./routes/root.routes");
const homeRouter = require("./routes/root.routes");
const cartRouter = require("./routes/cart.routes");

// setup ejs-a
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

// setup za statičko posluživanje
app.use(express.static(path.join(__dirname, "public")));

// setup rutera
app.use("/", homeRouter);

app.listen(3000);
