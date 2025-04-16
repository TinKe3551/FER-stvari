function osvjezi_prikaz_proizvoda(kategorija) {

    stari = document.getElementsByClassName("proizvod");
    for (let i = 0; i < stari.length; stari.item(0).remove());

    
    let prikaz = document.getElementById("proizvodi");
    novi = data["categories"][kategorija];

    for (let i = 0; i < novi.length ; i++) {

        let proizvod = document.createElement("div");

        proizvod.className = "proizvod";
        proizvod.id = novi[i]["name"];

        proizvod.innerHTML = '';

        let slika = document.createElement("img");
        slika.src = "./images/" + novi[i]["image"];
        slika.alt = "slika za " + novi[i]["name"];
        slika.className = "proizvod";

        let ikonica = document.createElement("img");
        ikonica.src = "./images/kosarica.png";
        ikonica.className = "ikonica";
        ikonica.style.opacity = 0;
        ikonica.style.width = "40px";
        ikonica.id = "pr_" + i.toString() + "_ik";

        let tekst = document.createElement("p");
        tekst.innerHTML = novi[i]["name"];

        let pr_brojac = document.createElement("p");
        if (novi[i]["amount"] > 0) pr_brojac.innerHTML = "u košarici: " + novi[i]["amount"];
        
        proizvod.appendChild(slika);
        proizvod.appendChild(ikonica);
        proizvod.appendChild(tekst);
        proizvod.appendChild(pr_brojac)

        proizvod.id = "pr_" + i.toString();

        proizvod.addEventListener("mouseenter", () => {
            let ik = document.getElementById("pr_" + i.toString() + "_ik");
            ik.style.opacity = 1;
        })

        proizvod.addEventListener("mouseleave", () => {
            let ik = document.getElementById("pr_" + i.toString() + "_ik");
            ik.style.opacity = 0;
        })

        proizvod.addEventListener("click", () => {

            let kosr_brojac = Number(localStorage.getItem("kosr_brojac"));
            kosr_brojac++;
            localStorage.setItem("kosr_brojac", kosr_brojac);

            data["basketsize"]++;
            document.getElementById("kosr_brojac").innerHTML = data["basketsize"];

            data["categories"][kategorija][i]["amount"]++;

            let proizvod = document.getElementById("pr_"+i.toString());
            proizvod.childNodes[proizvod.childNodes.length - 1].
            innerHTML = "u košarici: " + data["categories"][kategorija][i]["amount"].toString();
            
        })

        proizvod.style.cursor = "pointer";

        prikaz.appendChild(proizvod);

    }

    document.getElementById("nazivkat").innerHTML = kategorija;

}





document.getElementById("kategorija1").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Udžbenici iz matematike");
});
document.getElementById("kategorija2").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Zbirke zadataka iz matematike");
});
document.getElementById("kategorija3").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Udžbenici iz elektrotehničkih predmeta");
});
document.getElementById("kategorija4").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Zbirke zadataka iz elektrotehničkih predmeta");
});
document.getElementById("kategorija5").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Udžbenici iz računarskih predmeta");
});
document.getElementById("kategorija6").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Zbirke zadataka iz računarskih predmeta");
});
document.getElementById("kategorija7").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Udžbenici i zbirke zadataka iz ostalih predmeta");
});
document.getElementById("kategorija8").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Bilježnice sa stranicama s crtama");
});
document.getElementById("kategorija9").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Bilježnice s kariranim stranicama");
});
document.getElementById("kategorija10").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Bilježnice s praznim stranicama");
});

localStorage.setItem("kosr_brojac", 0);