var express = require("express");
var router = express.Router();

router.get("/", (req, res, next) => {
    res.redirect("/getCategories");
});

router.get("/getCategories", (req, res, next) => {
    res.render("home", {
        title: "FER knjižara",
        categories: [
            
        ]
    });
});



module.exports = router;
