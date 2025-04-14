function osvjezi_prikaz_proizvoda(kategorija) {

    stari = document.getElementsByClassName("proizvod");
    for (let i = 0; i < stari.length; stari.item(0).remove());



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
    osvjezi_prikaz_proizvoda("Udžbenici iz ostalih predmeta");
});
document.getElementById("kategorija8").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Zbirke zadataka iz ostalih predmeta");
});
document.getElementById("kategorija9").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Bilježnice s kariranim stranicama");
});
document.getElementById("kategorija10").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda("Bilježnice s praznim stranicama");
});

