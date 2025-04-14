function osvjezi_prikaz_proizvoda(kategorija) {

    stari = document.getElementsByClassName("proizvod");
    for (let i = 0; i < stari.length; stari.item(0).remove());

}



document.getElementById("kategorija1").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(1);
});
document.getElementById("kategorija2").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(2);
});
document.getElementById("kategorija3").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(3);
});
document.getElementById("kategorija4").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(4);
});
document.getElementById("kategorija5").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(5);
});
document.getElementById("kategorija6").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(6);
});
document.getElementById("kategorija7").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(7);
});
document.getElementById("kategorija8").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(8);
});
document.getElementById("kategorija9").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(9);
});
document.getElementById("kategorija10").addEventListener("click", () => {
    osvjezi_prikaz_proizvoda(10);
});