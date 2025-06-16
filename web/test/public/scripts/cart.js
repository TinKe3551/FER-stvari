for (let gumb_dodavanja in document.getElementsByClassName(
    "kosr_proizvod_dodaj",
)) {
    gumb_dodavanja.addEventListener("click", () => {
        let id = "br_" + gumb_dodavanja.id;
        console.log(id);
        let brojac = document.getElementById(id).innerHTML;
        brojac = parseInt(brojac);
        document.getElementById(id).innerHTML = brojac + 1;

        brojac = document.getElementById("kosr_brojac").innerHTML;
        brojac = parseInt(brojac);
        document.getElementById(id).innerHTML = brojac + 1;
    });
}

for (let gumb_dodavanja in document.getElementsByClassName(
    "kosr_proizvod_makni",
)) {
    gumb_dodavanja.addEventListener("click", () => {
        let id = "br_" + gumb_dodavanja.id;
        let brojac = document.getElementById(id).innerHTML;
        brojac = parseInt(brojac);
        document.getElementById(id).innerHTML = brojac - 1;

        brojac = document.getElementById("kosr_brojac").innerHTML;
        brojac = parseInt(brojac);
        document.getElementById(id).innerHTML = brojac - 1;
    });
}

for (let i = 0; i < 10; i++) {
    console.log(i);
}
