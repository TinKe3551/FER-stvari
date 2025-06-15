

for (let i = 0; i < 5; i++) {

    console.log(i);

    let proizvod = document.getElementById("pr_" + i);
    let ikonica = document.getElementById("ik_" + i);

    console.log("pr_" + i);
    console.log("ik_" + i);

    ikonica.style.opacity = 0;

    proizvod.addEventListener("mouseenter", () => {
        ikonica.style.opacity = 1;
    });

    proizvod.addEventListener("mouseleave", () => {
        ikonica.style.opacity = 0;
    });

}
