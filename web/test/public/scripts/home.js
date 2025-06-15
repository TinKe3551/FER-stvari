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

    proizvod.addEventListener("click", () => {
        // lokalno povećavanje brojača na košarici
        let brojac = document.getElementById("kosr_brojac").innerHTML;
        brojac = parseInt(brojac);
        document.getElementById("kosr_brojac").innerHTML = brojac + 1;

        // lokalno povećavanje brojača na proizvodu
        brojac = document.getElementById("br_" + i).innerHTML;
        brojac = parseInt(brojac);
        document.getElementById("br_" + i).innerHTML = brojac + 1;

        // povećavanje brojača na serveru
        fetch("/cart/add/:" + i, {
            method: "POST",
        });
    });
}
