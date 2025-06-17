for (let i = 0; true; i++) {
    try {
        console.log(i);

        let proizvod = document.getElementById("pr_" + i);
        let gumb = document.getElementById("g_" + i);

        console.log("pr_" + i);
        console.log("g" + i);

        gumb.addEventListener("click", () => {
            // lokalno povećavanje brojača na košarici
            let brojac = document.getElementById("kosr_brojac").innerHTML;
            brojac = parseInt(brojac);
            document.getElementById("kosr_brojac").innerHTML = brojac + 1;

            // lokalno povećavanje brojača na proizvodu
            brojac = document.getElementById("br_" + i).innerHTML;
            brojac = parseInt(brojac);
            document.getElementById("br_" + i).innerHTML = brojac + 1;

        });
    }

    catch (TypeError) {
        break;
    }
}
