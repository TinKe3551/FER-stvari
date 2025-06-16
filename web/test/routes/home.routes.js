var express = require("express");
var router = express.Router();
var session = require("express-session");
var data = require("../data/data");

// varijable koje se koriste pri učitavanju home stranice
let id = NaN;
let selected_category = "Trenutno nije odabrana nijedna kategorija";
let categories_names = [];
let category_data = [];


router.get("/", (req, res, next) => {
    res.redirect("/home_check_categories");
});

router.get("/home_check_categories", (req, res, next) => {

    // ako kategorije još nisu dohvaćene, dohvati ih
    if (categories_names.length === 0) {
        res.redirect("/home/getCategories");
    }

    res.redirect("/home");

})

router.get("/home", (req, res, next) => {


    // učitaj home stranicu
    res.render("home", {
        category_id: id,
        session: req.session,
        selected_category: selected_category,
        categories_names: categories_names,
        category_data: category_data,
    });

});

router.get("/home/getCategories", (req, res, next) => {
    // dohvati kategorije i preusmjeri na /home
    categories_names = data["categories_names"];
    res.redirect("/home");
});

router.get("/home/getProducts/:id", (req, res, next) => {

    // dohvati podatke
    id = parseInt(req.params.id.substring(1));
    selected_category = data["categories_names"][id];
    category_data = data["categories"][data["categories_names"][id]];

    //preusmjeri na /home
    res.redirect("/home")

});


module.exports = router;
