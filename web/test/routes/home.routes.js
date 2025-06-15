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
        categories_names: data["categories_names"],
        category_data: [],
    });
});

router.get("/home/getProducts/:id", (req, res, next) => {
    let id = parseInt(req.params.id.substring(1));
    res.render("home", {
        id: parseInt(req.params.id),
        session: req.session,
        title: "FER knjižara",
        selected_category: data["categories_names"][id],
        categories_names: data["categories_names"],
        category_data: data["categories"][data["categories_names"][id]],
    });


});

module.exports = router;
