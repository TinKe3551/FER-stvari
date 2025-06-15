var express = require("express");
var router = express.Router();

router.get("/cart", (req, res, next) => {
    res.render("cart");
});

router.post("/cart/add/:id", (req, res, next) => {

    console.log("post request for /cart/add/" + req.params.id);

    let category_id = req.params.id.substring(1, req.params.id.indexOf("_"));
    category_id = parseInt(category_id);

    let product_id = req.params.id.substring(req.params.id.indexOf("_") + 1);
    product_id = parseInt(product_id);

    console.log(category_id + " " + product_id);

    return res.sendStatus(204);

    res.redirect("/home/getProducts/:" + category_id);

});

module.exports = router;
