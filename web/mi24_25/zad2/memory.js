sessionStorage.setItem("score", 0);


function updateCounter(score) {

    let scoreCounter = document.getElementById("score");

    total = Number(sessionStorage.getItem("score")) + score
    sessionStorage.setItem("score", total);

    scoreCounter.innerHTML = "Score: " + total;

}


function cardClicked(index) {

    let active1 = sessionStorage.getItem("active1");
    let active2 = 0;
    
    if (active1 === index) return;

    let two_active = false;

    if (active1 === 0) {
        active1 = index;
        sessionStorage.setItem("active1", index);
    }
    else {
        active2 = index;
        two_active = true;
    }

    

    kartica = document.getElementById("card" + index);
    kartica.innerHTML = sessionStorage.getItem("card" + index).toString();

}


sessionStorage.setItem("card1", "A")
sessionStorage.setItem("card2", "A")
sessionStorage.setItem("card3", "B")
sessionStorage.setItem("card4", "B")
sessionStorage.setItem("card5", "C")
sessionStorage.setItem("card6", "C")
sessionStorage.setItem("card7", "D")
sessionStorage.setItem("card8", "D")
sessionStorage.setItem("card9", "E")
sessionStorage.setItem("card10", "E")
sessionStorage.setItem("card11", "F")
sessionStorage.setItem("card12", "F")
sessionStorage.setItem("card13", "G")
sessionStorage.setItem("card14", "G")
sessionStorage.setItem("card15", "H")
sessionStorage.setItem("card16", "H")

sessionStorage.setItem("active1", 0)

for (let i = 0; i < 20; i++) {

    let n1 = Math.floor(Math.random * 16) + 1;
    let n2 = Math.floor(Math.random() * 16) + 1;

    let c1 = sessionStorage.getItem("card" + n1);
    let c2 = sessionStorage.getItem("card" + n2);

    sessionStorage.setItem("card" + n1, c2);
    sessionStorage.setItem("card" + n2, c1);

}

for (let i = 1; i <= 16; i++) {
    console.log(i)
    console.log(sessionStorage.getItem("card" + i));
    document.getElementById("card" + i).addEventListener("click", cardClicked(i));
}

