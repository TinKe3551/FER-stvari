const express = require("express");
const app = express();

app.use(express.static("public/images/"));

app.get("/", function(req, res) {
    res.send("yeet <img src='/public/images/biljcrte.png'>");
})

app.listen(8000);
