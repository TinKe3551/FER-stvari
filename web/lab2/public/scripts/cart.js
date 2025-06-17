for (let i = 0; true; i++) {
    let gumb_dodavanja = document.getElementById("gd_" + i);
    if (gumb_dodavanja === null) break;

    gumb_dodavanja.addEventListener("click", () => {
        let brojac = document.getElementById("br_" + i).innerHTML;
        brojac = parseInt(brojac);
        document.getElementById("br_" + i).innerHTML = brojac + 1;

        brojac = document.getElementById("kosr_brojac").innerHTML;
        brojac = parseInt(brojac);
        document.getElementById("kosr_brojac").innerHTML = brojac + 1;
    });

    let gumb_oduzimanja = document.getElementById("gm_" + i);
    gumb_oduzimanja.addEventListener("click", () => {
        let brojac = document.getElementById("br_" + i).innerHTML;
        brojac = parseInt(brojac);

        if (brojac == 0) return;

        document.getElementById("br_" + i).innerHTML = brojac - 1;

        brojac = document.getElementById("kosr_brojac").innerHTML;
        brojac = parseInt(brojac);
        document.getElementById("kosr_brojac").innerHTML = brojac - 1;
    });
}
