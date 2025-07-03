var express = require("express");
var router = express.Router();
const quiz = require("../repo/quiz.repo");


var bodyParser = require("body-parser");
var urlencodedParser = bodyParser.urlencoded({extended:false});


var next_question_index = 0;
var n_total = quiz.questions.length;
var n_correct = 0;


router.get("/quiz/start", (req, res, next) => {

    next_question_index = 0;
    n_correct = 0;

    res.redirect("/quiz/question/:0");

})


router.get("/quiz/question/:num", (req, res, next) => {

    let num = req.params.num.substring(1);
    num = parseInt(num);
    if (num - 1 !== next_question_index) {
        res.redirect("/quiz/question/:" + (next_question_index+1));
    }

    // id: 1,
    // question: "Koji je rodni planet Lukea Skywalkera?",
    // options: ["Coruscant", "Hoth", "Tatooine", "Dagobah"],
    // correctAnswer: 2,
    // category: "Star Wars"

    res.render("question", {
        num: num,
        question: quiz["questions"][num-1]["question"],
        options: quiz["questions"][num-1]["options"],
        correctAnswer: quiz["questions"][num-1]["correctAnswer"],
        category: quiz["questions"][num-1]["category"],
        alphabet: "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    })

    console.log(quiz);

})


router.post("/quiz/question/:num/answer", urlencodedParser, (req, res, next) => {

    
    let answer = req.body.answer;
    answer = parseInt(answer);
    let num = req.params.num.substring(1);
    num = parseInt(num);

    console.log(answer + " " + quiz.questions[num-1].correctAnswer)

    if (quiz.questions[num-1].correctAnswer === answer) {
        n_correct++;
    }

    next_question_index++;

    console.log(n_correct + " correct answers")

    if (next_question_index < n_total) {
        res.redirect("/quiz/questions/:" + (num+1));
    }

    else {
        res.redirect("/quiz/results");
    }

})


router.get("/quiz/results", (req, res, next) => {

    let grade = n_correct / n_total;

    res.render("results", {
        correct: n_correct,
        total: n_total,
        grade: grade,
    });

})


module.exports = router;
