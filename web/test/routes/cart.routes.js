var express = require("express");
var router = express.Router();

router.get("/cart", (req, res, next) => {
    res.render("cart");
});

router.post("/cart/add/:id", (req, res, next) => {
    console.log("post request for /cart/add/" + req.params.id);
});

module.exports = router;
