var express = require("express");
var router = express.Router();
const data = require("../data/data");

router.get("/cart", (req, res, next) => {
    if (req.session.total_amount === undefined) req.session.total_amount = 0;

    let distinct_products = [];
    let product_names = [];

    for (let i = 0; i < data["categories_names"].length; i++) {
        for (
            let j = 0;
            j < data["categories"][data["categories_names"][i]].length;
            j++
        ) {
            if (req.session.data === undefined) break;
            let data_id = i + "_" + j;
            if (req.session.data[data_id] === undefined) continue;
            if (req.session.data[data_id] > 0) {
                distinct_products.push(data_id);
                product_names.push(
                    data["categories"][data["categories_names"][i]][j]["name"],
                );
            }
            console.log(i + " " + j + " " + data_id);
            console.log(JSON.stringify(distinct_products));
            console.log(JSON.stringify(product_names));
        }
    }

    res.render("cart", {
        total_amount: req.session.total_amount,
        distinct_products: distinct_products,
        product_names: product_names,
        amounts: req.session.data,
    });
});

router.post("/cart/add/:id", (req, res, next) => {
    if (req.session.total_amount === undefined) req.session.total_amount = 0;
    req.session.total_amount += 1;

    let id = req.params.id.substring(1);

    if (!req.session.data[id]) {
        req.session.data[id] = 1;
    } else {
        req.session.data[id] += 1;
    }

    console.log("new data in session: " + JSON.stringify(req.session.data));

    return res.sendStatus(204);
});

router.post("/cart/remove/:id", (req, res, next) => {
    let id = req.params.id.substring(1);

    if (req.session.total_amount === undefined) req.session.total_amount = 0;
    if (req.session.total_amount > 0 && req.session.data[id] > 0)
        req.session.total_amount -= 1;

    if (!req.session.data[id]) {
        req.session.data[id] = 0;
    } else if (req.session.data[id] > 0) {
        req.session.data[id] -= 1;
    }

    console.log("new data in session: " + JSON.stringify(req.session.data));

    return res.sendStatus(204);
});

module.exports = router;
