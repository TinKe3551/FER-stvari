var express = require("express");
var router = express.Router();

// ova glupost je potrebna kako bih mogao dohvatiti varijable iz post requestova koje su zadane preko formi od kojih su došli ti post requestovi
var bodyParser = require("body-parser");
var urlencodedParser = bodyParser.urlencoded({extended:false});

var movies = [
    "YEET", "Yeet", 
    "aabaabababababaaaababab", "kontekstno neovisna gramatika G",
    "Kako napraviti funkcionalan virtualni stroj", "nitko iz ztela ikad"
];


router.get("/movies", (req, res, next) => {

    res.render("movieList", {
        movies: movies,
    })

})


router.get("/movies/add", (req, res, next) => {

    res.render("addMovie");

})


router.post("/movies/add", urlencodedParser, (req, res, next) => {

    movies.push(req.body.movieTitle);
    movies.push(req.body.director);

    res.redirect("/movies");

})


router.post("/movies/delete/:id", (req, res, next) => {

    let i = parseInt(req.params.id.substring(1));

    movies.splice(i, 2);

    res.redirect("/movies");

})


module.exports = router;
