var express = require("express");
var router = express.Router();
var session = require("express-session");
var data = require("../data/data");

// varijable koje se koriste pri učitavanju home stranice
let id = NaN;
let selected_category =
    "Trenutno nije odabrana nijedna kategorija (ako kategorije nisu prikazane, kliknite na sliku knjige da se stranica ponovo učita";
let categories_names = [];
let product_amounts = []; // količine proizvoda za neku kategoriju
category_data = [];

router.get("/", (req, res, next) => {
    res.redirect("/home/getCategories");
});

router.get("/home", (req, res, next) => {
    console.log(req.session.id);

    if (req.session.total_amount === undefined) req.session.total_amount = 0;

    // učitaj home stranicu
    res.render("home", {
        category_id: id,
        session: req.session,
        selected_category: selected_category,
        categories_names: categories_names,
        product_amounts: product_amounts,
        total_amount: req.session.total_amount,
    });
});

router.get("/home/getCategories", (req, res, next) => {
    // dohvati kategorije i preusmjeri na /home
    categories_names = data["categories_names"];
    res.redirect("/home/getProducts/:0");
});

router.get("/home/getProducts/:id", (req, res, next) => {
    // dohvati podatke
    id = parseInt(req.params.id.substring(1));
    selected_category = data["categories_names"][id];
    category_data = data["categories"][selected_category];

    if (req.session.data === undefined) req.session.data = {};

    product_amounts = [];
    total_product_amount = 0;

    for (let i = 0; i < category_data.length; i++) {
        let data_id = id + "_" + i;

        product_amounts.push(req.session.data[data_id]);

        if (product_amounts[i] === undefined) product_amounts[i] = 0;

        console.log(data_id + ": " + product_amounts[i]);
        total_product_amount += product_amounts[i];
    }

    //preusmjeri na /home
    res.redirect("/home");
});

module.exports = router;
