var express = require("express");
var router = express.Router();
var data = require("../data/data");

router.get("/", (req, res, next) => {
    res.redirect("/home/getCategories");
});

router.get("/home", (req, res, next) => {
    res.redirect("/home/getCategories");
});

router.get("/home/getCategories", (req, res, next) => {
    res.render("home", {
        session: req.session,
        title: "FER knjižara",
        selected_category: "Trenutno nije odabrana nijedna kategorija",
        categories_names: ["yeet"],
    });
});

module.exports = router;
