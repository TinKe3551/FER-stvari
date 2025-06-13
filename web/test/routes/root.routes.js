var express = require("express");
var router = express.Router();

router.get("/", (req, res, next) => {
    res.render("home", {
        title: "FER knjižara",
    });
});

module.exports = router;
