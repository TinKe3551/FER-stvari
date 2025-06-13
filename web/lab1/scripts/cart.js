if (localStorage.getItem("kosr_brojac") === null)
        localStorage.setItem("kosr_brojac", 0);
document.getElementById("kosr_brojac").innerHTML =
        localStorage.getItem("kosr_brojac");

prazna = true;

for (let i = 0; localStorage.key(i) !== null; i++) {
        let ime = localStorage.key(i);

        if (ime.substring(0, 3) !== "pr_") continue;
        if (localStorage.getItem(ime) == null || localStorage.getItem(ime) == 0)
                continue;

        prazna = false;

        //alert(ime + ": " + localStorage.getItem(ime));

        let kosr_proizvod = document.createElement("div");
        kosr_proizvod.className = "kosr_proizvod";
        kosr_proizvod.id = "kosr_" + ime;

        let kosr_proizvod_naziv = document.createElement("div");
        kosr_proizvod_naziv.innerHTML = ime.substring(3);
        kosr_proizvod_naziv.className = "kosr_proizvod_naziv";

        let kosr_proizvod_dodaj = document.createElement("div");
        let kosr_proizvod_dodaj_img = document.createElement("img");
        kosr_proizvod_dodaj_img.src = "images/plus.png";
        kosr_proizvod_dodaj_img.className = "kosr_proizvod_dodaj";
        kosr_proizvod_dodaj.className = "kosr_proizvod_dodaj";
        kosr_proizvod_dodaj.appendChild(kosr_proizvod_dodaj_img);

        let kosr_proizvod_brojac = document.createElement("div");
        kosr_proizvod_brojac.innerHTML = localStorage.getItem(ime);
        kosr_proizvod_brojac.className = "kosr_proizvod_brojac";

        let kosr_proizvod_makni = document.createElement("div");
        let kosr_proizvod_makni_img = document.createElement("img");
        kosr_proizvod_makni_img.src = "images/minus.png";
        kosr_proizvod_makni_img.className = "kosr_proizvod_makni";
        kosr_proizvod_makni.className = "kosr_proizvod_makni";
        kosr_proizvod_makni.appendChild(kosr_proizvod_makni_img);

        kosr_proizvod.appendChild(kosr_proizvod_naziv);
        kosr_proizvod.appendChild(kosr_proizvod_dodaj);
        kosr_proizvod.appendChild(kosr_proizvod_brojac);
        kosr_proizvod.appendChild(kosr_proizvod_makni);

        kosr_proizvod_dodaj.addEventListener("click", () => {
                let kosr_brojac = localStorage.getItem("kosr_brojac");
                kosr_brojac++;
                localStorage.setItem("kosr_brojac", kosr_brojac);
                document.getElementById("kosr_brojac").innerHTML = kosr_brojac;

                let kosr_pr_brojac = document
                        .getElementById("kosr_" + ime)
                        .childNodes.item(2).innerHTML;
                kosr_pr_brojac++;
                document
                        .getElementById("kosr_" + ime)
                        .childNodes.item(2).innerHTML = kosr_pr_brojac;
                localStorage.setItem(ime, kosr_pr_brojac);
        });

        kosr_proizvod_makni.addEventListener("click", () => {
                let kosr_pr_brojac = document
                        .getElementById("kosr_" + ime)
                        .childNodes.item(2).innerHTML;
                if (kosr_pr_brojac == 0) return 0;
                kosr_pr_brojac--;
                document
                        .getElementById("kosr_" + ime)
                        .childNodes.item(2).innerHTML = kosr_pr_brojac;
                localStorage.setItem(ime, kosr_pr_brojac);

                let kosr_brojac = localStorage.getItem("kosr_brojac");
                kosr_brojac--;
                localStorage.setItem("kosr_brojac", kosr_brojac);
                document.getElementById("kosr_brojac").innerHTML = kosr_brojac;
        });

        document.getElementById("kosr_proizvodi").appendChild(kosr_proizvod);
}

if (prazna) {
        let kosr_prazna = document.createElement("div");
        kosr_prazna.className = "kosr_proizvod";
        kosr_prazna.innerHTML = "Košarica je trenutno prazna.";
        document.getElementById("kosr_proizvodi").appendChild(kosr_prazna);
}
