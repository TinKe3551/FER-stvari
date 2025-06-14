var express = require("express");
var router = express.Router();

router.get("/cart", (req, res, next) => {
    res.render("cart");
});

module.exports = router;
